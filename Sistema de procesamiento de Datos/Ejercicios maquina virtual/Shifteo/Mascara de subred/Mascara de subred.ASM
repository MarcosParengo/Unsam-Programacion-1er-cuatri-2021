.8086
.model small
.stack 100h
.data
     impresionIngresoMascara db "Ingrese la mascara de red",0dh, 0ah, 24h
     impresionIngresoDirRed db 0dh,0ah,"Ingrese la direccion de red",0dh, 0ah, 24h
     impresionIngresoDirIp db 0dh,0ah,"Ingrese la direccion ip",0dh, 0ah, 24h
     mascara db "000000000000"
     dirRed db "000000000000"
     dirIp db "000000000000"
.code
     main proc
        mov ax, @data   ;INICIALIZO EL DATA SEGMENT
        mov ds, ax

        mov ah, 9h  
        mov dx, offset impresionIngresoMascara 
        int 21h
        xor bx,bx
        mov cl,3
cargaMascara:  
        cmp bx, 12; ;Si se ingresaron 5 letras ya se va para afuera
        je terminoMascara   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO

        xor ax,ax
        mov al,bl
        mov cl,3
        div cl
        cmp ah,0
        je punto1
sigue1:
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        mov mascara[bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx    ;parecido a i++
        jmp cargaMascara
punto1:  
        cmp bx,0
        je sigue1
        mov ah, 2h  
        mov dx, '.' 
        int 21h
        jmp sigue1
terminoMascara:
        mov ah, 9h  
        mov dx, offset impresionIngresoDirRed 
        int 21h
        xor bx,bx
        
cargaDirRed:  
        cmp bx, 12; ;Si se ingresaron 5 letras ya se va para afuera
        je terminoDirRed   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO
        xor ax,ax
        mov al,bl
        mov cl,3
        div cl
        cmp ah,0
        je punto2
sigue2:
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        mov dirRed[bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx    ;parecido a i++
        jmp cargaDirRed 
punto2:  
        cmp bx,0
        je sigue2
        mov ah, 2h  
        mov dx, '.' 
        int 21h
        jmp sigue2
terminoDirRed:
        mov ah, 9h  
        mov dx, offset impresionIngresoDirIp 
        int 21h
        xor bx,bx
cargaDirIp:  
        cmp bx, 12; ;Si se ingresaron 5 letras ya se va para afuera
        je terminoDirIp   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO
        xor ax,ax
        mov al,bl
        mov cl,3
        div cl
        cmp ah,0
        je punto3
sigue3:
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        mov dirIp[bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx    ;parecido a i++
        jmp cargaDirIp
punto3:  
        cmp bx,0
        je sigue3
        mov ah, 2h  
        mov dx, '.' 
        int 21h
        jmp sigue3
terminoDirIp:           
        mov ax, 4c00h    
        int 21h
     main endp
   end main
