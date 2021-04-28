.8086
.model small
.stack 100h

.data
	bienvenida db "esto es una calculadora de 1 byte", 0dh, 0ah
	menu db 0dh, 0ah, "ingrese la operacion a realizar de la siguiente manera xxx+yyy (puede usar menos digitos)", 0dh, 0ah, 24h
	
	varTrabajo db " XXX# XXX" ; varTrabajo[0] Signo del 1er Operando
							  ; varTrabajo[1,2,3] es el Primer Operando
							  ; varTrabajo[4] es la Operacion
							  ; varTrabajo[5] Signo del 2do Operando
							  ; varTrabajo[6,7,8] es el 2do Operando

	op1 db "000", 0dh, 0ah, 24h
	op2 db "000", 0dh, 0ah, 24h
	menos db 0dh, 0ah, "-"
	rst db "000", 0dh, 0ah, 24h

	salto db 0dh,0ah, 24h

	ingOp1 db 0dh, 0ah, "ingrese el 1er Operando", 0dh, 0ah, 24h
	ingOp2 db 0dh, 0ah,"ingrese el 2do Operando", 0dh, 0ah, 24h

	divi0 db 0dh, 0ah,"no se puede dividir por 0 salame", 0dh, 0ah, 24h
	pasado db 0dh, 0ah, "mas de 1 byte? que te crees que estamos en el anio 2000??", 0dh, 0ah, 24h
.code

main proc
	mov ax, @data
	mov ds, ax
	mov ah, 9
	mov dx, offset bienvenida
	int 21h
	;GENERO CAJA DE LECTURA
	mov bx, 0 ;INICIALIZO BX para EL 1er OPERANDO
arriba:		
	mov ah, 1
	int 21h
	cmp al, 0dh 
	je conver3
	cmp varTrabajo[3],'X'
	jne esOp
esNeg2:		
	cmp al, 2dh
	je esNeg
oper:		
	cmp al, 30h
	jae casiNro
	jmp arriba
casiNro:
	cmp al, 39h
	jbe esNro
esNeg:
	mov varTrabajo[0+bx], '-'
	jmp arriba
esOp:	
	cmp varTrabajo[4],'#'
	jne esNeg2
	cmp al, 2dh
	je operacion
	cmp al, 2bh
	je operacion
	cmp al, '*'
	je operacion
	cmp al, '/'
	je operacion
	jmp oper
operacion:
	mov varTrabajo[4], al
	mov bx, 5
	jmp arriba
esNro:
	cmp varTrabajo[3+bx],'X'
	jne Cambio1
	mov varTrabajo[3+bx], al
	jmp arriba
conver3: 
	jmp conver		
Cambio1:
	cmp varTrabajo[2+bx], 'X'
	jne Cambio2 
	mov ah, varTrabajo[3+bx]
	mov varTrabajo[2+bx], ah
	mov varTrabajo[3+bx], al
	jmp arriba
Cambio2:
	cmp varTrabajo[1+bx], 'X'
	jne Error
	mov ah, varTrabajo[2+bx]
	mov varTrabajo[1+bx], ah
	mov ah, varTrabajo[3+bx]
	mov varTrabajo[2+bx], ah 
	mov varTrabajo[3+bx], al
	jmp arriba
Error:
	mov ah, 2
	mov dl, "E"
	int 21h
	jmp fin2
conver:
	mov cx, 9
	mov bx, 0
cambiaX: 
	cmp varTrabajo[bx],'X'
	jne conver2
	mov varTrabajo[bx],'0'
conver2: 
	inc bx
	loop cambiaX		
	;DH para el OP 1 y DL para el OP 2
	;ASCII TO REG OP1
	xor ax, ax
	xor dx, dx
	mov al, varTrabajo[1] ;GUARDO EL DIGITO ASCII MAS SIGNIFICATIVO EN AL
	sub al, 30h    ;CONVIERTO ESE DATO A NRO
	mov cl, 100    ;GUARDO EN CL LA CANTIDAD PARA MULTIPLICAR
	mul cl         ;MULTIPLICO
	add dl, al     ;GUARDO EL RESULTADO
	;CONSIGO DECENA
	mov al, varTrabajo[2]
	sub al, 30h
	mov cl, 10
	mul cl
	add dl, al 
	;CONSIGO UNIDAD
	mov al, varTrabajo[3]
	sub al, 30h
	add dl, al
	mov dh, dl ;GUARDE EL OP 1 EN DH
	;ASCII TO REG OP2
	xor ax, ax
	xor dl, dl ;LIMPIO DL PARA QUE NO ENSUCIE
	mov al, varTrabajo[6] ;GUARDO EL DIGITO ASCII MAS SIGNIFICATIVO EN AL
	sub al, 30h    ;CONVIERTO ESE DATO A NRO
	mov cl, 100    ;GUARDO EN CL LA CANTIDAD PARA MULTIPLICAR
	mul cl         ;MULTIPLICO
	add dl, al     ;GUARDO EL RESULTADO
	;CONSIGO DECENA
	mov al, varTrabajo[7]
	sub al, 30h
	mov cl, 10
	mul cl
	add dl, al 
	;CONSIGO UNIDAD
	mov al, varTrabajo[8]
	sub al, 30h
	add dl, al
	;CAMBIO SI CORRESPONDE EL Signo
	cmp varTrabajo[0], '-'
	je cambioOp1
otro:	
	cmp varTrabajo[5], '-'
	je cambioOp2
	jmp laburo
cambioOp1:
	neg dh
	jmp otro
cambioOp2:
	neg dl
	;AHORA TENGO LOS 2 OPERANDOS UNO EN dh y otro en dl
laburo:	
	cmp varTrabajo[4], '+'
	je suma
	cmp varTrabajo[4], '-'
	je resta
	cmp varTrabajo[4], '*'
	je multi
	cmp varTrabajo[4], '/'
	je divi
	;jmp opcion
fin2: jmp fin3
suma: 
	xor ax, ax
	mov al, dh
	add al, dl
	;jc mePase
	mov dh, al
	jmp regToAscii
resta:	
	sub dh, dl
	jmp regToAscii

multi:
	xor ax, ax
	mov al, dh
	mul dl
	;cmp ah, 0
	;jg mePase
	mov dh, al
	jmp regToAscii

divi:
	xor ax, ax
	mov al, dh
	cmp dl, 0
	je NoDiv
	idiv dl
	mov dh, al
	jmp regToAscii

;regToAscii rst
fin3: 
	jmp fin
regToAscii:	
	xor bx, bx
	cmp dh, 0
	jge regToAsciiPOS
	neg dh        ;HAGO EL COMPLEMENTO A2 DE EL REGISTRO
	mov bl, 1
regToAsciiPOS:	mov cl, dh ; USO CL como RECEPTOR DE EL NRO A CONVERTIR
	xor ax, ax
	mov al, cl ;CARGO EN EL REGISTRO ACUMULADOR (AX) EL VALOR QUE QUIERO CONVERTIR
	mov cl, 100
	div cl ; AHORA QUE DIVIDÍ EN AH TENGO EL RESTO Y EN AL EL RESULTADO
	add al, 30h ; SUMO 30 h para convertir el nro en caracter ascii

	mov rst[0], al; guardo el caracter en la posición mas significativa de la variable nro
	;GENERO CENTENA
	mov al, ah ; GUARDO EL NUEVO VALOR A DIVIDIR EN AL
	xor ah, ah ; LIMPIO AH (para que no me haga lio con la división)
	mov cl, 10 ; guardo el valor por el que voy a dividir en cl
	div cl     ; VUELVO A DIVIDIR
	add al, 30h
	mov rst[1], al
	;GENERO DECENA 
	add ah, 30h
	mov rst[2],ah	
	;GENERO UNIDAD
	mov ah, 9
	mov dx, offset salto
	int 21h
	cmp bx, 0
	je imprime
	mov ah, 2
	mov dl, '-'
	int 21h
imprime:
	mov ah,9
	mov dx, offset rst
	int 21h
	jmp fin
mePase:	
	mov ah,9 
	mov dx, offset pasado
	int 21h
	jmp fin
noDiv:
	mov ah,9 
	mov dx, offset divi0
	int 21h
fin:	mov ax, 4c00h
		int 21h

main endp
end main