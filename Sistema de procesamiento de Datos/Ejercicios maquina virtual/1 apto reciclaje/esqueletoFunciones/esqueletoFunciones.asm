.8086
.model small
.stack 100h
.data

.code
main proc
	mov ax, @data
	mov ds, ax
	;LLAMAN A LAS FUNCIONES HACIENDO CALL funcion


    mov ax, 4c00h
    int 21h

main endp

funcion proc

funcion endp
;.....
;.....
;..... PONEN LAS FUNCIONES QUE QUIERAN!


end main
