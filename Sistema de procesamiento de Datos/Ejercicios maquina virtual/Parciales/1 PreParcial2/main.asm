.8086
.model small
.stack 100h
.data
  nroBinario db "00000000",24h
  nro1 db "$$$",24h
  nro2 db "$$$",24h
  cantidadCaracteres db "$$$ veces",0dh,0ah,24h
  nro1Hexa db "$$",24h
  nro2Hexa db "$$",24h
  resultado db "$$$",0dh,0ah,24h
  negativo db "-",24h
  resultadoHex db "$$",0dh,0ah,24h
  simb db " ",24h
  linea db 0dh,0ah
  linea2 db 80 dup (04h),24h
  ingreseNumHexaAConv db 0dh,0ah,"Ingrese el numero Hexadecimal a convertir",0dh,0ah,24h
  ingreseNumHexa1 db 0dh,0ah,"Ingrese el primer numero Hexadecimal de dos digitos (Del que se restara el segundo numero)",0dh,0ah,24h
  ingreseNumHexa2 db 0dh,0ah,"Ingrese el segundo numero Hexadecimal de dos digitos (que se restara al primer numero)",0dh,0ah,24h
  ingreseNum db 0dh,0ah,"Ingrese un numero menor a 255",0dh,0ah,24h
  ingrese db 0dh,0ah,"Ingrese:",0dh,0ah
          db "1. para sumar numeros decimales (Hasta 255)",0dh,0ah
          db "2. para restar dos numeros hexa",0dh,0ah
          db "3. para ingresar un numero hexa y convertirlo a binario ",0dh,0ah
          db "4. para ingresar un numero hexa y convertirlo en decimal ",0dh,0ah
          db "5. para ingresar un texto, un caracter y ver cuantas veces aparece este en el",0dh,0ah
          db "primero",0dh,0ah,24h
  resultadoTxt db  0dh,0ah,"El resultado es:",24h
  textoError db  0ah,0dh,"Parece que alguien no sabe las reglas de las matematicas o lo que es un numero menor a 255, no te voy a decir el error orangutan",0dh,0ah,24h
  errorMenu db 0dh,0ah,"Por favor, ingrese una de las opcines listadas",0dh,0ah,24h
  textoErrorHexa db  0ah,0dh,"Parece que alguien no sabe lo que es un numero hexa",0dh,0ah,24h
  restaNeg db  0ah,0dh,"Tu resta dio negativo, Nice try",0dh,0ah,24h
  ingreseTextoParaBuscar db "Ingrese un texto para contar un caracter",0dh,0ah,24h
  ingreseCaracterBuscado db "Ingrese el caracter que desea contar en el texto ingresado",0dh,0ah,24h
  textoIntermedioHexToDec db " en hexadecimal es ",24h
  enDecimal db " en decimal",0dh,0ah,24h
  enBinario db " en binario",0dh,0ah,24h
  salto db 0dh,0ah,24h
  textoParaBuscar db 255 dup (24h)
  caracterBuscado db " ",24h
  caracteresContadosTxt db 0ah,0dh,"El caracter ingresado se repitio:",24h
.code

extrn asciiToReg:proc
extrn regToAscii:proc
extrn lectura:proc
extrn printar:proc
extrn calcular:proc
extrn asciiHexaToReg:proc
extrn regToAsciiHexa:proc
extrn contarCaracter:proc
extrn regToBin:proc

main proc
	mov ax, @data
	mov ds, ax

  mov ah, 06h
  mov al, 0
  int 10h
menu:
	mov bx, offset ingrese
	call printar
	xor bx,bx

	lea bx, simb
  mov dx,1
	call lectura
	xor bx,bx

  mov bx, offset linea
	call printar
	xor bx,bx

	cmp simb,'1'
	je opcionUnoIntermedio

  cmp simb,'2'
  je opcionDosIntermedio

  cmp simb,'3'
  je opcionTresIntermedio
   
  cmp simb, '4'
  je opcionCuatroIntermedio

  cmp simb, '5'
  je opcionCincoIntermedio

  cmp simb,'0'
  je opcionCero

  mov bx, offset errorMenu
	call printar
  jmp menu
opcionUnoIntermedio:
  jmp opcionUno
opcionDosIntermedio:
  jmp opcionDos
  opcionTresIntermedio:
  jmp opcionTres
opcionCuatroIntermedio:
  jmp opcionCuatro
opcionCincoIntermedio:
  jmp opcionCinco
opcionCero:
jmp fin
opcionCinco:
  mov bx, offset ingreseTextoParaBuscar
	call printar
	xor bx,bx

	lea bx, textoParaBuscar
  mov dx,255
	call lectura

  mov bx, offset ingreseCaracterBuscado
	call printar
	xor bx,bx

	lea bx, caracterBuscado
  mov dx,1
	call lectura

  lea bx, textoParaBuscar
  mov al, caracterBuscado
  call contarCaracter
  ;contarCaracter devuelve en cl y es el valor que deseo convertir

  mov bx, offset cantidadCaracteres
	call regToAscii
	mov bx, offset caracteresContadosTxt
	call printar
	mov bx, offset cantidadCaracteres
	call printar
jmp fin
opcionCuatro:
  mov bx, offset ingreseNumHexaAConv
  call printar
  xor bx,bx
  lea bx, nro1Hexa
  mov dx,2
  call lectura
  ;PASO EL ASCII A CONVERTIR EN BX CON EL STACK, RECIBO EL NUMERO CONVERTIDO EN DL o EN SI 255 SI HAY ALGUN ERROR
  lea bx, nro1Hexa
  push bx
  call asciiHexaToReg;Me devuelve el numero de la variable que le paso por bx en dx
  cmp si,255

  je errorHexaIntermedio

  mov cl,dl;Necesito en cl el numero a convertir
  mov bx, offset nro1
  call regToAscii
  
  mov bx, offset linea
	call printar
  mov bx, offset nro1Hexa
	call printar
  mov bx, offset textoIntermedioHexToDec
	call printar
  mov bx, offset nro1
	call printar
  mov bx, offset enDecimal
	call printar
  
jmp fin
errorHexaIntermedio:
  jmp errorHexa
opcionTres:
  mov bx, offset ingreseNumHexaAConv
	call printar
	xor bx,bx
  lea bx, nro1Hexa
  mov dx,2
	call lectura
	;PASO EL ASCII A CONVERTIR EN BX CON EL STACK, RECIBO EL NUMERO CONVERTIDO EN DL o EN SI 255 SI HAY ALGUN ERROR
	lea bx, nro1Hexa
	push bx
	call asciiHexaToReg
  cmp si,255
	je errorHexaIntermedio
  
  mov cl,dl
  lea bx,nroBinario
  call regToBin
 
  mov bx, offset linea
	call printar
  mov bx, offset nro1Hexa
	call printar
  mov bx, offset textoIntermedioHexToDec
	call printar
  mov bx, offset nroBinario
	call printar
  mov bx, offset enBinario
	call printar

  jmp fin
opcionDos:
  mov bx, offset ingreseNumHexa1
	call printar
  xor bx,bx
  lea bx, nro1Hexa
  mov dx,2
	call lectura
	;PASO EL ASCII A CONVERTIR EN BX CON EL STACK, RECIBO EL NUMERO CONVERTIDO EN DL o EN SI 255 SI HAY ALGUN ERROR
	lea bx, nro1Hexa
	push bx
	call asciiHexaToReg
  cmp si,255
	je errorHexa
  push dx

  mov bx, offset ingreseNumHexa2
	call printar
  xor bx,bx
  lea bx, nro2Hexa
  mov dx,2
	call lectura
	;PASO EL ASCII A CONVERTIR EN BX CON EL STACK, RECIBO EL NUMERO CONVERTIDO EN DL o EN SI 255 SI HAY ALGUN ERROR
	lea bx, nro2Hexa
	push bx
	call asciiHexaToReg
  cmp si,255
	je errorHexa
  push dx

  mov cl,'2';Para restar
	pop dx
	mov bl,dl
	pop dx
	mov al,dl
	mov si,0
	call calcular;devuelve el resultado en cl
  cmp si, 254
  jne hexaPositivo
  mov bx, offset restaNeg
	call printar
  jmp fin
hexaPositivo:
  ;RegToAsciiHexa Recibe en cl el valor a convertir. Calcular lo devolvio en cl
  mov bx, offset resultadoHex
	call regToAsciiHexa
  mov bx, offset linea
	call printar
  mov bx, offset resultadoTxt
	call printar
  mov bx, offset resultadoHex
	call printar
  jmp fin
errorHexa:
	mov bx, offset textoErrorHexa
	call printar
	jmp fin
opcionUno:
	mov bx, offset ingreseNum
	call printar
	xor bx,bx

	lea bx, nro1
  mov dx,3
	call lectura

	xor bx,bx
	;PASO EL ASCII A CONVERTIR EN BX CON EL STACK, RECIBO EL NUMERO CONVERTIDO EN DL o EN SI 255 SI HAY ALGUN ERROR
	lea bx, nro1
	push bx
	call asciiToReg
	cmp si,255
	jne noError1Opcion1
	mov bx, offset textoError
	call printar
	jmp fin
noError1Opcion1:
	push dx
	mov bx, offset ingreseNum
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
	jne noError2Opcion1
	mov bx, offset textoError
	call printar
	jmp fin
noError2Opcion1:
	push dx
	xor bx,bx
	
	mov cl,'1';Para sumar
	pop dx
	mov bl,dl
	pop dx
	mov al,dl

	mov si,0
	call calcular;devuelve el resultado en cl
	cmp si,255
	jne noErrorCalcOpcion1

	mov bx, offset textoError
	call printar
	jmp fin
noErrorCalcOpcion1:	
	;en cl ya esta el resultado
  mov bx, offset linea
	call printar
	mov bx, offset resultado
	call regToAscii
	mov bx, offset resultadoTxt
	call printar
	mov bx, offset resultado
	call printar
fin:
  mov ax, 4c00h
  int 21h
main endp
end main
