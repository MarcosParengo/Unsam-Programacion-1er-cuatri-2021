
.8086
.model small
.stack 100h

.data
	salto db 0ah,0dh,24h
	izquierda db 179," ",24h
	derecha db " ",179,24h
  tarriba db 0DAh,0c4h,0c4h,0c4h,0bfh," ",0DAh,0c4h,0c4h,0c4h,0bfh," ",0DAh,0c4h,0c4h,0c4h,0bfh," ",0DAh,0c4h,0c4h,0c4h,0bfh," ",0dh,0ah
          db 0b3H,"   ",0b3H," ",0b3H,"   ",0b3H," ",0b3H,"   ",0b3H," ",0b3H,"   ",0b3H,0dh,0ah,24h
  
  tabajo  db 0b3H,"   ",0b3H," ",0b3H,"   ",0b3H," ",0b3H,"   ",0b3H," ",0b3H,"   ",0b3H,0dh,0ah
          db 0c0h,0c4h,0c4h,0c4h,0d9h," ",0c0h,0c4h,0c4h,0c4h,0d9h," ",0c0h,0c4h,0c4h,0c4h,0d9h," ",0c0h,0c4h,0c4h,0c4h,0d9h,0dh,0ah,24h
  nabajo1 db "  1     2     3     4   ",0ah,0dh,24h
  nabajo2 db "  5     6     7     8   ",0ah,0dh,24h
  
	simbolos db 01h,02h,03h,04h,05h,0bh,0bh,0ch


.code

public lectura
public printar
public Clearscreen
public imprimirOchoCartas
public esperaTiempo

;En dx se pasan cuantas lineas imprime y en si el offset de la variable con los simbolos
imprimirOchoCartas proc
  push ax
  push bx
  push cx
inicioFila:
  push dx
  lea bx,tarriba
  int 80h
  xor cx,cx
  mov cx,0
inicio:
  cmp cx,4
  je saltoLinea
  push cx
  lea bx,izquierda
  int 80h
  mov ah,02h
  mov dl,[si]
  inc si
  int 21h
  lea bx,derecha
  int 80h
  mov ah,02h
  mov dl,32
  int 21h
  pop cx
  inc cx
  jmp inicio

saltoLinea:
  lea bx,salto
  int 80h
  lea bx,tabajo
  int 80h
  pop dx
  cmp dl,2
  je primerLinea
  lea bx,nabajo2
  int 80h
  jmp segundaLinea
primerLinea:
  lea bx,nabajo1
  int 80h
segundaLinea:
  dec dl
  cmp dl,0
  je finImpresion
  jmp inicioFila
finImpresion:
  pop cx
  pop bx
  pop ax
  ret
imprimirOchoCartas endp

;Paso por bh los segundos que deseo esperar
esperaTiempo proc
	  push ax
	  push cx
	  push dx

      mov ah, 2ch ;Tiempo del sistema
      int 21h     ;Ch = hora cl = minutos dh = segundos dl = 1/100 segundos
      add dh,bh
      cmp dh,59
      jbe noHaceFalta
      sub dh,59
noHaceFalta:
      mov bh,dh
      push bx
noPasoTiempo:
      mov ah, 2ch ;Tiempo del sistema
      int 21h 
      pop bx  
      cmp bh,dh
      jbe YaPasoTiempo
      push bx
      jmp noPasoTiempo
YaPasoTiempo:
	  pop dx
	  pop cx
	  pop ax
	  ret
esperaTiempo endp


Clearscreen proc 
	push ax
	push es
	push cx
	push di
	mov ax,3
	int 10h
	mov ax,0b800h
	mov es,ax
	mov cx,1000
	mov ax,7
	mov di,ax
	cld
	rep stosw
	pop di
	pop cx
	pop es
	pop ax
	ret 
Clearscreen endp

;lea bx, nro para pasar la variable en la que va a guardar lo leido
;Recibe por bx la variable en la que va a guardar lo leido
;Recibe en dx la longitud maxima de lo que puede leer
lectura proc
		push ax
		push cx
		mov si,bx
		add si,dx
carga:  
        cmp bx, si; ;Si se ingresaron 5 letras ya se va para afuera
        je afuera   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        cmp al,0dh
        je afuera

        mov [bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx    ;parecido a i++
        jmp carga 
afuera:
		pop cx
		pop ax
		ret
lectura endp

;Funcion Calculadora
;en ax el primer numero, bx el segundo, cx el numero indicando la operacion (1->suma;2->resta;3->multiplicacion;4->division)
;devulve el resultado en cx
;vas a necesitar 3 de los 4 registros, pushea tus cosas xq seguro tenes algo importante rey
;si->255 error
;  |->254 negativo
;Num Negativos:(Despues de invocar la funcion)
;	cmp si, 254
;	jne regToAsciiNoNeg
;	neg cl
;Recibe por bx lo que imprimira
printar proc
		push ax
		push bx
		
		mov ah, 9h 
		mov dx, bx
		int 21h

		pop bx
		pop ax
		ret
printar endp

end