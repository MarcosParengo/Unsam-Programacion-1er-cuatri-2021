.8086
.model small
.stack 100h
.data
;Jump out of range
  bienvenido db "Bienvenido a mi programa",0dh,0ah, 24h ;0dh retorno de carro,0ah bajada de linea,24h signo pesos
  ingrese db "Ingrese un texto para que el programa cuente las vocales y las consonantes",0dh,0ah,24h
 
  cartel1 db 0dh,0ah,"Vocales",0dh,0ah,24h
  cartel2 db 0dh,0ah,"Consonantes",0dh,0ah,24h
  texto db 255 dup (24h),0dh,0ah,24h
  contVocal db "000",0dh,0ah,24h
  contConsonante db "000",0dh,0ah,24h

.code
     main proc
        mov ax, @data   ;INICIALIZO EL DATA SEGMENT
        mov ds, ax

        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset bienvenido ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h

        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset ingrese  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h
        
        mov bx,0  ;BX registro base, se puede mover por la ram, es como la variable i;Le asigno 0
        
carga:  
        cmp bx, 255; ;Si se ingresaron 255 letras ya se va para afuera
        je afuera   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        cmp al,0dh
        je afuera
        mov texto[bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx    ;parecido a i++
        jmp carga 
afuera:
        mov cl,0
        mov dl,0
        xor bx,bx

sigue:  
        cmp texto[bx],24h
        je regToAscii
        cmp texto[bx],40h
        ja casiLetra
incrementa:
        inc bx
        jmp sigue
casiLetra:
        cmp texto[bx],5ah
        jbe esMayuscula
        cmp texto[bx],60h     
        ja  casiMinuscula 

casiMinuscula:
        cmp texto[bx],7ah
        jbe esMinuscula
        jmp incrementa
esMayuscula:
        cmp texto[bx],41h
        je vocal
        cmp texto[bx],45h
        je vocal
        cmp texto[bx],49h 
        je vocal
        cmp texto[bx],4Fh
        je vocal
        cmp texto[bx],55h
        je vocal
        inc dl
        jmp incrementa
esMinuscula:
        cmp texto[bx],61h
        je vocal
        cmp texto[bx],65h
        je vocal
        cmp texto[bx],69h 
        je vocal
        cmp texto[bx],6fh
        je vocal
        cmp texto[bx],75h
        je vocal

        inc dl
        jmp  incrementa

vocal:
        inc cl
        jmp incrementa

regToAscii:
        xor ax,ax
        mov al,cl;cargo en el registro acumulador el valor  convertir
        mov cl,100
        div cl;ahora que dividi en ah tengo el resto y en al el resultado
        add al,30h
        mov contVocal[0],al

        mov al,ah
        xor ah,ah
        mov cl,10
        div cl
        add al,30h
        mov contVocal[1],al

        add ah,30h
        mov contVocal[2],ah

        xor ax,ax
        mov al,dl;cargo en el registro acumulador el valor  convertir
        mov dl,100
        div dl;ahora que dividi en ah tengo el resto y en al el resultado
        add al,30h
        mov contConsonante[0],al

        mov al,ah
        xor ah,ah
        mov dl,10
        div dl
        add al,30h
        mov contConsonante[1],al

        add ah,30h
        mov contConsonante[2],ah

        mov ah, 9h
        mov dx, offset cartel1
        int 21h
        mov ah,9
        mov dx,offset contVocal
        int 21h
        mov ah, 9h
        mov dx, offset cartel2
        int 21h
        mov ah,9
        mov dx,offset contConsonante
        int 21h

terminar:
        mov ax, 4c00h    ;LLAMO AL SERVICIO 4c00h DE LA INTERRUPCION 21:deseo terminar mi programa
        int 21h          ;TERMINAR LA EJECUCION
     main endp

   end main
