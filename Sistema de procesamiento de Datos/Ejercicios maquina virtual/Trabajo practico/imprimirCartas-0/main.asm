.8086
.model small
.stack 100h
.data
  simb db " ",24h
  linea db 0dh,0ah
  linea2 db 80 dup (04h),24h
  simbolos db 01h,05h,02h,02h,05h,01h,0ch,0ch
  dadasVuelta db 15,15,15,15,15,15,15,15
  seleccione db "Por favor, elija la primer carta que desea dar vuelta, f para salir",0ah,0dh,24h
  cartaSeleccionada db "$$"
  seleccione2 db "Por favor, elija la segunda carta que desea dar vuelta, f para salir",0ah,0dh,24h
  cartaSeleccionada2 db "$$"
  error db 0ah,0dh,"Las cartas seleccionadas no son iguales, vuelva a intentarlo",0ah,0dh,24h
  salto db 0ah,0dh,24h
  correcto db "Las cartas seleccionadas son iguales",0ah,0dh,24h

  ;0bfh esquina derecha arriba
  ;0d9h esquina derecha abajo
  ;0DAh esquina izquierda arriba
  ;0c0h esquina izquierda abajo
  ;0c4h linea horizontal
  ;0b3H linea vertical

.code

extrn Clearscreen:proc
extrn imprimirOchoCartas:proc
extrn esperaTiempo:proc
extrn lectura:proc

main proc
	mov ax, @data
	mov ds, ax

  mov ah, 06h
  mov al, 0
  int 10h

  call Clearscreen;Limpio la pantalla para proceder a imprimir las cartas mostrando los simbolos
  lea si,simbolos;Cargo el offset del array de los 8 simbolos que van a ir adentro de las
                 ;cartas en si ya que asi lo pide la funcion
  mov dl,2;Indico que voy a imprimir dos filas de 4 cartas
  call imprimirOchoCartas;Llamo a la funcion para imprimir las cartas

  mov bh,3;Paso por bh cuantos segundos deseo esperar
  call esperaTiempo
inicio:
  call Clearscreen;Limpio la pantalla para proceder a imprimir las cartas dadas vueltas
  lea si,dadasVuelta;Cargo el offset del array de los 8 simbolos que van a ir adentro de las
                 ;cartas en si ya que asi lo pide la funcion
  mov dl,2;Indico que voy a imprimir dos filas de 4 cartas
  call imprimirOchoCartas;Llamo a la funcion para imprimir las cartas

seleccioneCarta1:
  lea bx,seleccione
  int 80h

  lea bx,cartaSeleccionada
  mov dx,1
  call lectura
  cmp cartaSeleccionada,'f'
  jne noFin
    jmp fin
noFin:
  cmp cartaSeleccionada,31h
  jb seleccioneCarta1
  cmp cartaSeleccionada,38h
  ja seleccioneCarta1
  mov bl,cartaSeleccionada[0]
  sub bl,31h
  mov al,simbolos[bx]
  mov dadasVuelta[bx],al

  call Clearscreen
  lea si,dadasVuelta
  mov dl,2
  call imprimirOchoCartas

seleccioneCarta2:
  lea bx,seleccione
  int 80h
  lea bx,cartaSeleccionada
  int 80h
  lea bx,salto
  int 80h
  lea bx,seleccione2
  int 80h
  lea bx,cartaSeleccionada2
  mov dx,1
  call lectura
  cmp cartaSeleccionada2,'f'
  je fin
  cmp cartaSeleccionada2,31h
  jb seleccioneCarta2
  cmp cartaSeleccionada2,38h
  ja seleccioneCarta2
  mov bl,cartaSeleccionada2[0]
  sub bl,31h
  mov al,simbolos[bx]
  mov dadasVuelta[bx],al

  ;En al tengo el simbolo de la segunda carta seleccionada
  mov bl,cartaSeleccionada[0]
  sub bl,31h
  mov ah,simbolos[bx]
  ;En ah tengo el simbolo de la primer carta seleccionada
  call Clearscreen
  lea si,dadasVuelta
  mov dl,2
  call imprimirOchoCartas

  cmp ah,al
  je sigue

;Si no son iguales, imprimo error y vuelvo al principio
  lea bx,error
  int 80h

  mov bh,3;Paso por bh cuantos segundos deseo esperar
  call esperaTiempo

  
  xor bx,bx
  mov bl,cartaSeleccionada[0]
  sub bl,31h
  mov dadasVuelta[bx],15
  xor bx,bx
  mov bl,cartaSeleccionada2[0]
  sub bl,31h
  mov dadasVuelta[bx],15


  jmp inicio
sigue:
  lea bx,correcto
  int 80h
  jmp inicio

fin:
  mov ax, 4c00h
  int 21h
main endp
end main
