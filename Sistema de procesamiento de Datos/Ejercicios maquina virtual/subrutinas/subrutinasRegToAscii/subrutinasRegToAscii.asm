.8086
.model small
.stack 100h
.data

  nro db "255",24h
  variable db "000",0ah,0dh,24h

.code
main proc
	mov ax, @data
	mov ds, ax
	
	lea bx, nro
	push bx
	call asciiToReg

	;El valor a convertir debe estar en cl
	mov cl,142
	;La variable en bx
	mov bx, offset variable
	call regToAscii

    mov ax, 4c00h
    int 21h
main endp

asciiToReg proc
	;RECIBE EN POR STACK EL OFFSET DE UNA VARIALBE DB E IMPRIME CARACTER A CARACTER HASTA ENCONTRAR UN $
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
	add dl,al
	
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
	;RECIBE EN BX EL OFFSET DE UNA VARIABLE , GUARDA EN ELLA EL VALOR EN ASCCI DEL NUMERO GUARDADO EN CL
	push ax
	push dx
	
	xor dx,dx
	mov al,cl;cargo en el registro acumulador el valor  convertir
	mov cl,100
arribaRTA:
	cmp dx, 3
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
	inc dx
jmp arribaRTA 
finRTA:
	pop dx
	pop ax
	ret
regToAscii endp
end main
