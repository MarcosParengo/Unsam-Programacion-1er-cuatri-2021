.8086
.model small
.stack 100h
.data
     cuidado db "ALARMA ACTIVADA LLAMANDO AL 911",0dh, 0ah, 24h
     impresion db "Error en alarma numero "
     error db 31h,0dh, 0ah, 24h
.code
     main proc
        mov ax, @data   ;INICIALIZO EL DATA SEGMENT
        mov ds, ax
        
        mov al, 10110110b
        push AX
        mov bl, 11111111b
        xor al,bl
        cmp al,0
        jne DANGER
        jmp fin

DANGER:
        mov ah,9
        mov dx,offset cuidado
        int 21h
xZonas:
        mov cx,8
        pop AX
arriba:
        shr al,1
        jnc errorEnZona
continua:
        inc error
        loop arriba
        jmp fin
errorEnZona:
        mov ah,9
        mov dx,offset impresion
        int 21h
        jmp continua
fin:
        mov ax, 4c00h    
        int 21h
     main endp
   end main
