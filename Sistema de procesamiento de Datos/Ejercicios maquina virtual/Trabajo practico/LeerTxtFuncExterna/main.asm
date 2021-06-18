.8086
.model small
.stack 100h
.data
  simb db " ",24h
  linea db 0dh,0ah
  linea2 db 80 dup (04h),24h
  simbolos db 01h,05h,02h,02h,05h,01h,0ch,0ch
  vacio db 15,15,15,15,15,15,15,15

.code

extrn leerArchivo:proc
extrn Clearscreen:proc
extrn imprimirOchoCartas:proc
extrn esperaTiempo:proc

main proc
	mov ax, @data
	mov ds, ax

  mov ah, 06h
  mov al, 0
  int 10h

  call Clearscreen
  lea si,simbolos
  mov dl,2
  call imprimirOchoCartas

  mov bh,4
  call esperaTiempo

  call Clearscreen
  lea si,vacio
  mov dl,2
  call imprimirOchoCartas

fin:
  mov ax, 4c00h
  int 21h
main endp
end main
