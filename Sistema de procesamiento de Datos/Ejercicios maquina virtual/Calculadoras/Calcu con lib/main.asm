.8086
.model small
.stack 100h
.data

  nro1 db "$$$",24h
  nro2 db "$$$",24h
  resultado db "$$$",0dh,0ah,24h
  negativo db "-",24h
  simb db " ",24h
  ingrese db 0dh,0ah,"Ingrese un numero menor a 255",0dh,0ah,24h
  ingrese2 db  0dh,0ah,"Ingrese 1 para sumar, 2 para restar, 3 para multiplicar y 4 para dividir",0dh,0ah,24h
  resultadoTxt db  0dh,0ah,"El resultado es:",24h
  textoError db  0ah,0dh,"Parece que alguien no sabe las reglas de las matematicas o lo que es un numero menor a 255, no te voy a decir el error orangutan",0dh,0ah,24h

.code

extrn asciiToReg:proc
extrn regToAscii:proc
extrn lectura:proc
extrn printar:proc
extrn calcular:proc
main proc
	mov ax, @data
	mov ds, ax
	
	mov bx, offset ingrese
	call printar
	xor bx,bx

	lea bx, nro1
    mov dx,3
	call lectura

	xor bx,bx
	;PASO EL ASCII A CONVERTIR EN BX CON EL STACK, RECIBO EL NUMERO CONVERTIDO EN DL
	lea bx, nro1
	push bx
	call asciiToReg
	cmp si,255
	jne noErrorMain
	mov bx, offset textoError
	call printar
	jmp fin
noErrorMain:
	push dx
	mov bx, offset ingrese
	call printar
	xor bx,bx
	lea bx,nro2
    mov dx,3
	call lectura
	;PASO EL ASCII A CONVERTIR EN BX CON EL STACK, RECIBO EL NUMERO CONVERTIDO EN DL
	lea bx, nro2
	push bx
	call asciiToReg
	cmp si,255
	jne noErrorMain1
	mov bx, offset textoError
	call printar
	jmp fin
noErrorMain1:
	push dx

	mov bx, offset ingrese2
	call printar
	xor bx,bx
	lea bx,simb
    mov dx,1
	call lectura
	
	mov cl,simb
	pop dx
	mov bl,dl
	pop dx
	mov al,dl

	mov si,0
	call calcular;devuelve el resultado en cl
	cmp si,255
	jne noErrorCalc

	mov bx, offset textoError
	call printar
	jmp fin
noErrorCalc:
	cmp cl, 0
	jge regToAsciiNoNeg
	neg cl
	mov si,2
	regToAsciiNoNeg:	
	;en cl ya esta el resultado
	mov bx, offset resultado
	call regToAscii
	mov bx, offset resultadoTxt
	call printar
	cmp si,2
	jne noNegativoPrint
	mov bx, offset negativo
	call printar
noNegativoPrint:
	mov bx, offset resultado
	call printar
fin:
    mov ax, 4c00h
    int 21h
main endp
end main
