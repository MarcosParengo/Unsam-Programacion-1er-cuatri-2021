.8086
.model small
.stack 100h
.data
     cuidado db 0dh,0ah,"ALARMA ACTIVADA LLAMANDO AL 911",0dh, 0ah, 24h
     aSalvo db 0dh,0ah,"No hay ninguna irregularidad en las alarmnas, siga descansando mi rey",0dh, 0ah, 24h
     impresion db "Error en alarma numero "
     error db 31h,0dh, 0ah, 24h
     insulto db 0dh,0ah,"salame tenias q meter 0 o 1 (Es un lector de binarios)",0dh, 0ah, 24h
     bienvenida db 0dh,0ah,"Ingrese la senial de cada sensor (1 normal, 0 irregularidad)",0dh, 0ah, 24h
.code
     main proc
        mov ax, @data   ;INICIALIZO EL DATA SEGMENT
        mov ds, ax
        ;
reset:  
        mov error[0],31h
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
        jb NoUnoOCero
        cmp al, 31h
        ja NoUnoOCero
        cmp al, 30h
        je cero 
        cmp al, 31h
        je uno
sigue:
        inc bx    ;parecido a i++
        jmp carga 
NoUnoOCero:
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
        ;
afuera: 
        xor ax,ax
        mov al,dl
        push AX
        mov bl, 11111111b
        xor al,bl
        cmp al,0
        jne DANGER
        mov ah,9
        mov dx,offset aSalvo
        int 21h
        jmp reset
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
        jmp reset
errorEnZona:
        mov ah,9
        mov dx,offset impresion
        int 21h
        jmp continua
finOperacion:    
        mov ax, 4c00h    
        int 21h
     main endp
   end main
