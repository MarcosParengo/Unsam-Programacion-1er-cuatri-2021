.8086
.model small
.stack 100h

.data

 var db "000 ", 24h

.code

  main proc
        mov ax, @data
        mov ds, ax

      xor ax,ax   ;AL en 0
empieza:
	  mov bx, 0   ;Inicializo BX en 0
        mov cl,3
hora: 
      push cx
      mov ah, 2ch ;Tiempo del sistema
      int 21h     ;Ch = hora cl = minutos dh = segundos dl = 1/100 segundos
      call randNmro
      pop cx
      cmp bx, 20 ;En BX esta la cantidad de veces que se actualizo la hora, en este caso me fijo si se actualizo 10 veces DL
                  ;5 centecimas * bx (5cent*20=1 segundo)
      je afuera  ;Si es igual, salto a imprimir la variable

      cmp al, dl ;Si los centisegundos son igual al valor que hay en AL
      je hora    ;Si es igual, vuelvo a actualizar la hora, sino, sigue con el programa

	mov al, dl ;Muevo el valor de los centisegundos actuales a AL
      inc bx     ;Incremento BX en 1
      jmp hora   ;Vuelvo a actualizar la hora

afuera:
	mov ah, 9   ;Imprimo
	mov dx, offset var
	int 21h 
	jmp empieza ;Vuelvo a empezar el ciclo

      main endp

;Genero un numero random
randNmro PROC
      push ax
      push bx
      push cx
      
      mov ax, 25173  
      mul dl
      add ax, 13849
      mov cx, 10

      xor dx,dx
      mov cx,10
      div cx
      add dl, '0'
      mov ah,02h
      int 21h
      nop
      nop
      nop

      pop cx
      pop bx
      pop ax
      ret
randNmro ENDP
   end main