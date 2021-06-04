.8086
.model small
.stack 100h
.data
	nro db "000", 0dh, 0ah, 24h
	nroImp db "000", 0dh, 0ah, 24h
	var db 255 dup (24h), 24h
	salto db 0dh, 0ah, 24h
.code
	main proc
		mov ax, @data
		mov ds, ax

		mov ah, 0
		mov al, 0
		mov dx, offset var
		call lectura

		mov bx, offset var
		call printar

		mov bx, offset salto
		call printar

		mov ah, 1
		mov al, 3
		mov dx, offset nro
		call lectura

		; mov ah, 1
		; int 21h
		; mov nro[0], al
		; mov ah, 1
		; int 21h
		; mov nro[1], al
		; mov ah, 1
		; int 21h
		; mov nro[2], al

		mov bx, offset salto
		call printar

		lea bx, nro
		push bx
		call asciiToReg

		mov bx, offset nroImp
		mov dx, cx
		call regToAscii

		call printar

		mov ax, 4c00h
		int 21h
	main endp

	lectura proc
		;Recibe en ah, el modo de trabajo (0 para indefinido, 1 para definido por cantidad de caracteres)
		;recibe en al el parametro modificador segun el modo
			;Modo 0 (0 corta con 0dh, 1 corta con 24h, si no es ninguno de esos cortara con el caracteres ingresado por al)
			;Modo 1 se ingresara la cantidad de lecturas que realizara la funcion
		;recibe en dx el offset de la variable donde se guardara el texto
		push ax
		push bx
		push cx
		push dx
		push si

		xor cx, cx
		mov bx, dx
		cmp ah, 0
		je modo0
		mov cl, al
		carga:
			mov ah, 1
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
			mov [bx], al
			inc bx
		jmp continuar

		finLectura:
		pop si
		pop dx
		pop cx
		pop bx
		pop ax
		ret
	lectura endp

	regToAscii proc
	;Recibe en un registro (DX), el nro a convertir y en bx el offset de la variable donde almacenara los caracteres
	;que correspondan al nro.
		push ax
		push bx
		push cx
		push dx
		pushf

		xor cx, cx
		xor ax, ax

		mov al, dl
		mov cl, 100
		div cl
		add al, 30h
		mov byte ptr [bx], al

		mov al, ah
		xor ah, ah
		mov cl, 10
		div cl
		add al, 30h
		mov [bx+1], al

		add ah, 30h
		mov [bx+2], ah

		popf
		pop dx
		pop cx
		pop bx
		pop ax
		ret
	regToAscii endp

	asciiToReg proc
	;Recibe utilizando el STACK un offset de una variable de 3 acracteres y guarda el mismo en un registro para poder operarlo
		push bp
		mov bp, sp

		push ax
		push dx
		push si
		pushf

		mov si, ss:[bp+4]
		xor ax, ax
		xor cx, cx
		xor dx, dx
		;consigo centena
		mov al, [si]
		sub al, 30h
		mov cl, 100
		mul cl
		add dl, al

		;Consigo decena
		mov al, [si+1]
		sub al, 30h
		mov cl, 10
		mul cl
		add dl, al

		;consigo la unidad
		mov al, [si+2]
		sub al, 30h
		add dl, al

		mov cx, dx

		popf
		pop si
		pop dx
		pop ax
		pop bp
		ret 2
	asciiToReg endp

	printar proc
		push ax
		push bx
		push dx

		arriba:
			cmp byte ptr[bx], 24h
			je fin
			mov ah, 2
			mov dl, byte ptr[bx]
			int 21h
			inc bx
		jmp arriba

		fin:
		pop dx
		pop bx
		pop ax
		ret
	printar endp
end main