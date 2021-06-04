.8086
.model small
.stack 100h

.data
	var db 255 dup (24h)
	nro db "000",24h

	nroImp db "000",24h
	
.code

	main proc
		mov ax, @data
		mov ds, ax

		mov ah, 0
		mov al, "/"
		mov dx, offset var
		call lectura ;recibe en ah el modo con el que se va a trabajar , y en al el caracter modificador
					 ; recibe en dx el offset donde guardar lo leido



		mov ah, 1
		mov al, 3
		mov dx, offset nro
		call lectura ;recibe en ah el modo con el que se va a trabajar , y en al el caracter modificador
					 ; recibe en dx el offset donde guardar lo leido




		lea bx, nro ;GUARDO EL OFFSET DE NRO EN BX
		push bx            ;ENVIO EL VALOR DE BX AL STACK PARA QUE asciiToReg LO UTILICE
		call asciiToReg

		mov bx, offset nroImp 
		mov dx, cx
		call regToAscii ;RECIBE EN DX EL NRO A CONVERTIR Y EN BX EL OFFSET PARA GUARDARLO
		mov bx, offset nroImp 
		call printar


		mov ax, 4c00h
		int 21h
	main endp

	lectura proc
		;recibe en ah el modo de trabajo (0 para indefinido, 1 para definido por cantidad de caracteres)
		;recibe en al el parametro modificador segun el modo
			; MODO 0 (0 corta con 0dh, 1 corta con 24h, si no es ninguno de esos cortará con el ascii del caracter ingresado en al)
			; MODO 1 se ingresará la cantidad de lecturas que realizará la funcion
		;recibe en dx el offset de la variable donde se guardará el texto

		push cx
		push bx
		push ax
		push si
		push dx

		xor cx, cx
		mov bx, dx
		mov si, bx
		add si, 255
		cmp ah, 0
		je modo0
		mov cl, al
carga:	mov ah, 1
		int 21h
		mov byte ptr [bx], al
		inc bx 
		loop carga
		jmp finLectura

modo0: 
		cmp al, 0
		je finEnter
		cmp al, 1
		je finPesos
		mov dl, al
		jmp continuar

finEnter:
		mov dl, 0dh
		jmp continuar
finPesos:
		mov dl, 24h
		jmp continuar

continuar:

		mov ah, 1
		int 21h
		cmp al, dl
		je finLectura
		cmp bx, si
		je finLectura
		mov [bx], al
		inc bx
		jmp continuar

finlectura:

		pop dx
		pop si
		pop ax
		pop bx
		pop cx
		ret
	lectura endp

	regToAscii proc
	;recibe en un registro (dx), el nro a convertir y en bx, el offset de la variable donde almacenará los caracteres
	; que correspondan al nro. 

		push cx
		push ax
		push bx
		push dx
		pushf

		mov cx, dx ; USO CL como RECEPTOR DE EL NRO A CONVERTIR
		xor ax, ax
		mov al, cl ;CARGO EN EL REGISTRO ACUMULADOR (AX) EL VALOR QUE QUIERO CONVERTIR
		mov cl, 100
		div cl ; AHORA QUE DIVIDÍ EN AH TENGO EL RESTO Y EN AL EL RESULTADO
		add al, 30h ; SUMO 30 h para convertir el nro en caracter ascii

		mov [bx], al; guardo el caracter en la posición mas significativa de la variable nro
		;GENERO CENTENA
		mov al, ah ; GUARDO EL NUEVO VALOR A DIVIDIR EN AL
		xor ah, ah ; LIMPIO AH (para que no me haga lio con la división)
		mov cl, 10 ; guardo el valor por el que voy a dividir en cl
		div cl     ; VUELVO A DIVIDIR
		add al, 30h
		mov [bx+1], al
		;GENERO DECENA 
		add ah, 30h
		mov [bx+2],ah	
		;GENERO UNIDAD

		popf
		pop dx
		pop bx
		pop ax
		pop cx
		ret 
	regToAscii endp

	asciiToReg proc
	;Recibe utilizando el STACK un offset de una variable de 3 caracteres y guarda el mismo en un registro para poder operarlo.
	;Devuelve el valor que corresponda en cx

		push bp     ;GUARDO EL ESTADO DE BP por las dudas
		mov bp, sp  ;ASIGNO EL VALOR DEL STACK POINTER AL BP PARA PODER APUNTAR AL MISMO LUGAR

		push dx     ;GUARDO EL ENTORNO
		push ax
		push si
		pushf

		mov si, ss:[bp+4] ; ME QUEDO CON EL PRIMER PARAMETRO 
		xor dx, dx
		;CONSIGO CENTENA
		mov al, [si] ;GUARDO EL DIGITO ASCII MAS SIGNIFICATIVO EN AL
		sub al, 30h    ;CONVIERTO ESE DATO A NRO
		mov cl, 100    ;GUARDO EN CL LA CANTIDAD PARA MULTIPLICAR
		mul cl         ;MULTIPLICO
		add dl, al     ;GUARDO EL RESULTADO

		;CONSIGO DECENA
		mov al, [si+1]
		sub al, 30h
		mov cl, 10
		mul cl
		add dl, al 

		;CONSIGO UNIDAD
		mov al, [si+2]
		sub al, 30h
		add dl, al 
		mov cx, dx

		popf
		pop si           ;GUARDO EL ENTORNO
		pop ax
		pop dx
		pop bp           ;DEVUELVO EL VALOR A BP

	ret 2                ;USO RET 2 PORQUE PASE UN PARAMETRO Y AHORA DEBO LIMPIAR EL STACK.
	asciiToReg endp

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


end 