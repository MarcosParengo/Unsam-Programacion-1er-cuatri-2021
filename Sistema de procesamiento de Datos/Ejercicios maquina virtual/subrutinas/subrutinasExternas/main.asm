.8086
.model small
.stack 100h
.data

  nro db "000",24h
  variable db "000",0ah,0dh,24h
  salto db 0ah,0dh,"El numero pasado por asciiToReg y luego por regToAscii es:",24h
  ingrese db "Ingrese un numero menor a 255",0dh,0ah,24h
  textoError db  0ah,0dh,"El numero ingresado fue mayor a 255 :(",0dh,0ah,24h

.code

extrn asciiToReg:proc
extrn regToAscii:proc
extrn lectura:proc
extrn printar:proc

main proc
	mov ax, @data
	mov ds, ax
	
	mov bx, offset ingrese
	call printar

	lea bx, nro
	call lectura

	xor bx,bx
	;PASO EL ASCII A CONVERTIR EN BX CON EL STACK, RECIBO EL NUMERO CONVERTIDO EN DL
	lea bx, nro
	push bx
	call asciiToReg
	cmp si,255
	jne noErrorMain
	mov bx, offset textoError
	call printar
	jmp fin
noErrorMain:
	;El valor a convertir debe estar en cl
	mov cl,dl
	;La variable en bx
	mov bx, offset variable
	call regToAscii

	mov bx,offset salto
	call printar

	mov bx, offset variable
	call printar
fin:
    mov ax, 4c00h
    int 21h
main endp

end main
