.8086
.model small
.stack 100h
.data

  texto db 255 dup (24h),24h
  ingrese db "Ingrese una palabra para que el programa cuente sus vocales",0dh,0ah,24h
  cantidad  db 0
			db 0
			db 0
			db 0
			db 0
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

    mov ax, 4c00h
    int 21h
main endp

end main
