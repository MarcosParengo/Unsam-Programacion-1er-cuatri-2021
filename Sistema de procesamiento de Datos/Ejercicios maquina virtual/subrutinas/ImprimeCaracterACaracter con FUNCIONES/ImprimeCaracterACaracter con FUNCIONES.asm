.8086
.model small
.stack 100h
.data
	variable db "HOLA MUNDO",0dh, 0ah, 24h
.code
main proc
	mov ax, @data
	mov ds, ax
	;LLAMAN A LAS FUNCIONES HACIENDO CALL funcion
	mov bx, offset variable
	call printar

	lea bx, variable
	push bx
	call printarStack


    mov ax, 4c00h
    int 21h

main endp

printar proc
	;RECIBE EN BX EL OFFSET DE UNA VARIALBE DB E IMPRIME CARACTER A CARACTER HASTA ENCONTRAR UN $
	push ax
	push dx
arriba:
	cmp byte ptr [bx], 24h
	je fin
	mov ah, 2
	mov dl, byte ptr [bx]
	int 21h
	inc bx
jmp arriba 
fin:
	pop dx
	pop ax
	ret
printar endp


printarStack proc
	;RECIBE EN POR STACK EL OFFSET DE UNA VARIALBE DB E IMPRIME CARACTER A CARACTER HASTA ENCONTRAR UN $
	push bp
	mov bp, sp
	push ax
	push dx


	mov bx, ss:[bp+4] ;ACCEDO AL VALOR DEL OFFSET QUE ME PASARON AL PRINCIPIO

arribaStack:
	cmp byte ptr [bx], 24h
	je finStack
	mov ah, 2
	mov dl, [bx]
	int 21h
	inc bx
jmp arribaStack 

finStack:
	pop dx
	pop ax
	pop bp
	ret 2

printarStack endp
;.....
;.....
;..... PONEN LAS FUNCIONES QUE QUIERAN!


end main
