.8086
.model small
.stack 100h

.data

 variable db "Hola Mundo",0dh,0ah,24h ;DECLARACION DE LA VARIABLE
 variable2 db "Chau mundo",24h

.code
    main proc
        mov ax, @data
        mov ds, ax

        mov dx, offset variable
        mov ah, 9h
        int 21h

        mov dx,offset variable2;
        mov ah,9h;
        int 21h

        mov ax, 4c00h;LLAMAMOS AL SERVICIO DE DOS PARA TERMINAR LA EJECUCION
        int 21h
    main endp
  end main
