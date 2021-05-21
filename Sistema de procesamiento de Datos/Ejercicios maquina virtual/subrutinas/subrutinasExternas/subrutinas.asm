.8086
.model small
.stack 100h

.data
		varproc db 0dh, 0ah, "entre al programa proceso$"
		varsubproc db 0dh, 0ah, "entre al sub proceso$"
		;variables utilizadas en la libreria
.code
public asciiToReg
public regToAscii
public lectura
public printar
asciiToReg proc
	;RECIBE EN POR STACK EL OFFSET DE UNA VARIALBE DB Y LO PASA A EL REGISTRO DL
	push bp
	mov bp, sp
	push ax
	push bx
	push cx
	xor dx,dx
	mov bx, ss:[bp+4] ;ACCEDO AL VALOR DEL OFFSET QUE ME PASARON AL PRINCIPIO
	mov cl,100
arribaStack:
	cmp byte ptr [bx], 24h
	je finStack

	mov al,[bx]
	sub al,30h
	mul cl
	jnc noErrorPar
	mov si,255
	jmp finStack
noErrorPar:
	add dl,al
	jnc noErrorDef
	mov si,255
	jmp finStack
noErrorDef:
	xor ax,ax
	mov al,cl
	mov cl,10
	div cl;ahora que dividi en ah tengo el resto y en al el resultado
	mov cl,al
	xor ax,ax
	inc bx
	jmp arribaStack 
finStack:
	pop cx 
	pop bx
	pop ax
	pop bp
	ret 2
asciiToReg endp
regToAscii proc
	;EL VALOR A CONVERTIR ESTA EN CL, CUANDO SE VA CONVIRTIENDO A ASCII, LO GUARDA EN LA VARIABLE DE LA QUE BX TIENE GUARDADO EL OFFSET
	push ax
	push dx
	
	xor dx,dx
	mov al,cl;cargo en el registro acumulador el valor  convertir
	mov cl,100
arribaRTA:
	cmp dl, 3
	je finRTA
	mov ah,0
	;En el reg acumulador ya tengo el valor a convertir
	div cl;ahora que dividi en ah tengo el resto y en al el resultado
	add al,30h
	mov[bx],al
	mov al, ah
	mov ah,0

	push ax
	mov al,cl
	mov cl,10
	div cl;ahora que dividi en ah tengo el resto y en al el resultado
	mov cl,al
	pop ax

	inc bx
	inc dl
jmp arribaRTA 
finRTA:
	pop dx
	pop ax
	ret
regToAscii endp
lectura proc
		push ax
		push bx
		push cx
		push dx
		mov bx,si
		add si,3
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
		pop dx
		pop cx
		pop bx
		pop ax
		ret
lectura endp
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