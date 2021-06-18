.8086
.model small
.stack 100h
.data
     insulto db 0dh,0ah,"salame tenias q meter 0 o 1 (Es un lector de binarios)",0dh, 0ah, 24h
     bienvenida db 0dh,0ah,"Ingrese un numero binario de hasta 8 bits",0dh, 0ah, 24h
     impresion db 0dh,0ah,"lestoo ",0dh, 0ah, 24h
.code
     main proc
        mov ax, @data   ;INICIALIZO EL DATA SEGMENT
        mov ds, ax
reset:
        mov ah,9
        mov dx,offset bienvenida
        int 21h
        mov bx,0  ;BX registro base, se puede mover por la ram, es como la variable i;Le asigno 0
        mov dl,0
carga:  
        cmp bx, 8
        je afuera
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        cmp al, 0dh
        je afuera
        cmp al, 30h
        jb error
        cmp al, 31h
        ja error
        cmp al, 30h
        je cero 
        cmp al, 31h
        je uno
sigue:
        inc bx    ;parecido a i++
        jmp carga 
error:
        mov ah,9
        mov dx,offset insulto
        int 21h
        jmp reset
cero:  
        shl dl,1
        jmp sigue
uno:
        shl dl,1
        inc dl
        jmp sigue
afuera:
        mov ah,9
        mov dx,offset impresion
        int 21h
fin:
        mov ax, 4c00h    
        int 21h
     main endp
   end main
