
.8086
.model small
.stack 100h

.data
		varproc db 0dh, 0ah, ""
		varsubproc db 0dh, 0ah, ""
.code
public asciiToReg
public regToAscii
public lectura
public printar
public calcular 
public asciiHexaToReg
public regToAsciiHexa
public contarCaracter
public regToBin

;Registro a binario, llega en cl el valor a convertir y en bx el offset de la variable en la que se lo guarda
regToBin proc
	push si
	push dx
	push ax

	mov dl,cl
	mov cl,8
inicioRegABin:
	cmp bx,8
	je finRegABin
	shl dl,1
	jc unoBinario
	mov[bx],30h
	jmp casiVueltaInicioRegABin
unoBinario:
	mov[bx],31h
casiVueltaInicioRegABin:
	inc bx
	loop inicioRegABin
finRegABin:
	pop ax
	pop dx
	pop si
	ret
regToBin endp

;Recibe en bx el offset de la variable, en ah el caracter que quiere contar, devuelve en cl la cantidad de veces que aparecio el caracter
contarCaracter proc
	push dx
	xor cx,cx
busquedaSiguenteCaracter:
	cmp  byte ptr [bx],24h
	je finRecorridaTexto
	cmp byte ptr [bx],al
	je caracterEncontrado
	jmp prevBusquedaSiguienteCaracter
caracterEncontrado:
	inc cl
prevBusquedaSiguienteCaracter:
	inc bx
	jmp busquedaSiguenteCaracter
finRecorridaTexto:
	pop dx
	ret
contarCaracter endp

;!Importante la funcion puede devolver en dx o en si, pushearlos antes de hacer el llamado
;No hay que preocuparse por que el usuario ingrese 020 por ejemplo (Se procesan la cantidad de cifras)
;Funcion ascii to reg:
;Recibe Por stack el offset de la variable a convertir
;Puede  hay dos casos posibles:
;1. La funcion convierte correctamente el numero retorna en el registro DL el numero convertido
;2. Hay un error (El numero a convertir es mayor a 255), por lo que devuelve en si 255
asciiHexaToReg proc
	;RECIBE EN POR STACK EL OFFSET DE UNA VARIALBE DB Y LO PASA A EL REGISTRO DL
	push bp
	mov bp, sp
	push ax
	push bx
	push cx
	xor dx,dx
	mov bx, ss:[bp+4] ;ACCEDO AL VALOR DEL OFFSET QUE ME PASARON AL PRINCIPIO
	
    mov dx,0
    push bx
cuentaCaracteres:;Cuento los caracteres para saber si son uno o dos y ahi hacer la cantidad de vueltas necesarias para convertir el asciiHexa a hexa
	cmp byte ptr [bx], 24h
    je finContarCaracteres
    inc dx
    inc bx
    jmp cuentaCaracteres;Evita que A en vez de 0A sea A0
finContarCaracteres:
    mov cl,1
armaMultiplicadorInicialCLHexa:;Si es un caracter lo multplica por uno al ser soloo unidades, sino el primer caracte lo multiplica por 16 y luego el segundo por 1
    cmp dl,1
    je clSettedHexa
    mov al,16
    mul cl
    mov cl,al
    xor ax,ax
    dec dl
    jmp armaMultiplicadorInicialCLHexa
clSettedHexa:
    pop bx
    mov dx,0
arribaStackHexa:
	cmp byte ptr [bx], 24h
	je finStackHexa

	mov al,[bx]
	cmp al,'9';
	jbe casiNumHexa
	;Checkeo si esta de la "A" a la "F" o de la "a" a la "f"
	cmp al,"A"
	jae casiLetraHexa
	cmp al,"a"
	jae casiLetraHexa
	mov si,255;Error
	jmp finStackHexa
casiLetraHexa:
	cmp al,"F"
	jbe LetraHexaMayus
	cmp al,"f"
	jbe LetraHexaMinus
	mov si,255;Error
	jmp finStackHexa
LetraHexaMinus:
	sub al,57h
	jmp valoresBienHexa
LetraHexaMayus:
	sub al,37h
	jmp valoresBienHexa
casiNumHexa:
	cmp al,'0'
	jae numHexa
	mov si,255;Error
	jmp finStackHexa
numHexa:;1 al 9
	sub al,30h
valoresBienHexa:
	mul cl
	jnc noErrorParcialHexa
	mov si,255
	jmp finStackHexa
noErrorParcialHexa:
	add dl,al
	jnc noErrorDefinitivoHexa
	mov si,255
	jmp finStackHexa
noErrorDefinitivoHexa:
	xor ax,ax
	mov al,cl
	mov cl,10
	div cl;ahora que dividi en ah tengo el resto y en al el resultado
	mov cl,al
	xor ax,ax
	inc bx
	jmp arribaStackHexa 
finStackHexa:
	pop cx 
	pop bx
	pop ax
	pop bp
	ret 2
asciiHexaToReg endp
regToAsciiHexa proc

;Funcion reg to ascii Hexa:
;Recibe: -Por CL el numero que se desea convertir
;        -Por BX el offset de la variable en la que se guarda el resultado
;EL VALOR A CONVERTIR ESTA EN CL, CUANDO SE VA CONVIRTIENDO A ASCII, LO GUARDA EN LA VARIABLE DE LA QUE BX TIENE GUARDADO EL OFFSET
	push ax
	push dx
	
	xor dx,dx
	mov al,cl;cargo en el registro acumulador el valor  convertir
	mov cl,16
arribaRTAHex:
	cmp dl, 2;a las tres vueltas termina
	je finRTAHex
	mov ah,0
	;En el reg acumulador ya tengo el valor a convertir
	div cl;ahora que dividi en AH tengo el resto y en AL el resultado, el resultado ya es la centena, el resto las unidades+las decenas
	
	cmp al,0ah
	jb numRTAHex

	add al,37h;Agrego 37h para pasar la decena a ascii (Letra)
	mov[bx],al;guardo el caracter
	jmp salteaConvNumAAscii
numRTAHex:
	add al,30h;Agrego 30h para pasar la decena a ascii (Numero)
	mov[bx],al;guardo el caracter
salteaConvNumAAscii:
	mov al, ah;Guardo en el registro acumulador el valor de las unidades+ las decenas, con lo que seguire laburando
	mov ah,0;limpio AH

	push ax;como voy a dividir y tengo informacion importante en ax, lo pusheo

	mov al,cl;voy a dividir cl por 10 para en la proxima vuelta dividir las decenas+unidades por diez, para obtener el caracter que corresponde a las decenas
	mov cl,16
	div cl;ahora que dividi en ah tengo el resto y en al el resultado
	mov cl,al
	pop ax;recupero la informacion importante

	inc bx;paso a la segunda posicion de la variable en la que queda guardado el valor del registro para popsicionar alli las centenas
	inc dl;incremento dl para marcar que ya di la vuelta
jmp arribaRTAHex 
finRTAHex:
	pop dx
	pop ax
	ret
regToAsciiHexa endp

asciiToReg proc
	;RECIBE EN POR STACK EL OFFSET DE UNA VARIALBE DB Y LO PASA A EL REGISTRO DL
	push bp
	mov bp, sp
	push ax
	push bx
	push cx
	xor dx,dx
	mov bx, ss:[bp+4] ;ACCEDO AL VALOR DEL OFFSET QUE ME PASARON AL PRINCIPIO
	
    mov dx,0
    push bx
cuentaNumerosReales:
	cmp byte ptr [bx], 24h
    je finContar
    inc dx
    inc bx
    jmp cuentaNumerosReales;Evita que 20 en vez de 020 sea 200
finContar:
    mov cl,1
armaMultiplicadorInicialCL:
    cmp dl,1
    je clSetted
    mov al,10
    mul cl
    mov cl,al
    xor ax,ax
    dec dl
    jmp armaMultiplicadorInicialCL
clSetted:
    pop bx
    mov dx,0
    ;mov cl,100
arribaStack:
	cmp byte ptr [bx], 24h
	je finStack

	mov al,[bx]
	sub al,30h
	mul cl
	jnc noErrorParcial
	mov si,255
	jmp finStack
noErrorParcial:
	add dl,al
	jnc noErrorDefinitivo
	mov si,255
	jmp finStack
noErrorDefinitivo:
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

;Funcion reg to ascii:
;Recibe: -Por CL el numero que se desea convertir
;        -Por BX el offset de la variable en la que se guarda el resultado
regToAscii proc
	;EL VALOR A CONVERTIR ESTA EN CL, CUANDO SE VA CONVIRTIENDO A ASCII, LO GUARDA EN LA VARIABLE DE LA QUE BX TIENE GUARDADO EL OFFSET
	push ax
	push dx
	
	xor dx,dx
	mov al,cl;cargo en el registro acumulador el valor  convertir
	mov cl,100
arribaRTA:
	cmp dl, 3;a las tres vueltas termina
	je finRTA
	mov ah,0
	;En el reg acumulador ya tengo el valor a convertir
	div cl;ahora que dividi en AH tengo el resto y en AL el resultado, el resultado ya es la centena, el resto las unidades+las decenas
	add al,30h;Agrego 30h para pasar la centena a ascii
	mov[bx],al;guardo el caracter
	mov al, ah;Guardo en el registro acumulador el valor de las unidades+ las decenas, con lo que seguire laburando
	mov ah,0;limpio AH

	push ax;como voy a dividir y tengo informacion importante en ax, lo pusheo

	mov al,cl;voy a dividir cl por 10 para en la proxima vuelta dividir las decenas+unidades por diez, para obtener el caracter que corresponde a las decenas
	mov cl,10
	div cl;ahora que dividi en ah tengo el resto y en al el resultado
	mov cl,al
	pop ax;recupero la informacion importante

	inc bx;paso a la segunda posicion de la variable en la que queda guardado el valor del registro para popsicionar alli las centenas
	inc dl;incremento dl para marcar que ya di la vuelta
jmp arribaRTA 
finRTA:
	pop dx
	pop ax
	ret
regToAscii endp

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

calcular proc
	push dx

	mov ah,0
	mov bh,0
	mov ch,0
	mov ch,0

	cmp cl,'1'
	je suma
	cmp cl, '2'
	je resta
	cmp cl, '3'
	je multiplicacion
	cmp cl, '4'
	je division

	jmp Error

suma:
	add al,bl
	mov cl,al
	jc error
	jmp fin
resta:
	sub al,bl
	mov cl,al
	jc negativo
	jmp fin
negativo:
	mov si,254
	jmp fin
multiplicacion:
	mov cl,bl
	mul cl
	mov cl,al
	cmp ah,0
	jg error
	jmp fin
division:
	cmp bl,0
	je error
	mov cl,bl
	div cl
	mov cl,al
	jmp fin 
error:
	mov si,255
fin:
	pop dx
	ret
calcular endp


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