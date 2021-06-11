.8086
.model small
.stack 100h
.data
  simb db " ",24h
  linea db 0dh,0ah
  linea2 db 80 dup (04h),24h
  ingreseTexto db 0dh,0ah,"Ingrese un texto de hasta 255 caracteres",0dh,0ah,24h
  ingrese db 0dh,0ah,"Ingrese una de las siguientes opciones",0dh,0ah
          db "1. Cifrar el texto con una cantidad que ingresara luego",0dh,0ah
          db "2. Convertir cada caracter en hexa",0dh,0ah
          db "3. Indicar la hora del sistema",0dh,0ah
          db "4. Ingresar un numero de 1 a 59 para mostrar un cartel de alarma al pasar",0dh,0ah
          db "   esta cantidad de segundos se muestre un cartel de alarma",0dh,0ah
          db "0. Salir",0dh,0ah,24h
  textoMain db 255 dup (24h)
  errorMenu db 0dh,0ah,"Por favor, ingrese una de las opcines listadas",0dh,0ah,24h

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

extrn opcion2:proc
extrn opcion3:proc
extrn opcion4:proc

main proc
	mov ax, @data
	mov ds, ax

  mov ah, 06h
  mov al, 0
  int 10h

  lea bx,ingreseTexto
  int 80h;Int 80h es mi interrupcion para imprimir

  lea bx, textoMain
  mov dx,255
	call lectura;Lectura es mi funcion "caja de lectura", en bx le paso el offset de la variable en la que se guardara lo que se ingrese
              ;En dx le paso cuantos caracteres como maximo quiero leer
	xor bx,bx

menu:
  lea bx,ingrese
  int 80h
	xor bx,bx

	lea bx, simb
  mov dx,1
	call lectura
	xor bx,bx

  mov bx, offset linea
	int 80h
	xor bx,bx

	cmp simb,'1'
	je opcionUno

  cmp simb,'2'
  je opcionDos

  cmp simb,'3'
  je opcionTres
   
  cmp simb, '4'
  je opcionCuatro

  cmp simb,'0'
  je opcionCero

  mov bx, offset errorMenu
	int 80h
  jmp menu

opcionCero:
jmp fin
opcionCuatro:
  call opcion4
  jmp fin
opcionTres:
  call opcion3
  jmp fin
opcionDos:
  lea bx,textoMain
  call opcion2
  jmp fin
opcionUno:
	mov bx, offset textoMain
	int 80h
fin:
  mov ax, 4c00h
  int 21h
main endp
end main
