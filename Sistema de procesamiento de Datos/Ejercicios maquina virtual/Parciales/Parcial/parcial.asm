.8086
.model small
.stack 100h
.data
;Jump out of range
  bienvenido db "Bienvenido a mi programa",0dh,0ah, 24h ;0dh retorno de carro,0ah bajada de linea,24h signo pesos
  ingrese db "Ingrese un texto para que el programa cuente las letras, los puntos y las comas",0dh,0ah,24h

  pasado db 0dh, 0ah, "Este es un mensaje triste que nunca se va a mostrar pq si no dejo ingresar mas de 255 caracteres la cant de vocales+puntos+letras nunca va a ser mas de 255", 0dh, 0ah, 24h
  terminoDeContar db 0dh,0ah,"El recuento final dio que hay:",0dh,0ah 
  contLetras db "000"
  cartel1 db " vocales",0dh,0ah
  contPuntos db "000"
  cartel2 db " puntos",0dh,0ah
  contComas db "000"
  cartel3 db " comas",0dh,0ah
  contTotal db "000"
  cartel4 db " vocales,puntos y comas",0dh,0ah,24h

  texto db 255 dup (24h),0dh,0ah,24h
  

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
        cmp bx, 255; ;CORROBORA SI LA CAJA DE CARGA DIO MAS DE 255 VUELTAS (SE INGRESARON 255 CARACTERES)
        je afuera   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        cmp al,0dh ;CORROBORA SI EL CARACTER INGRESADO ES UN ENTER
        je afuera ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO
        mov texto[bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx
        jmp carga 
afuera:
        mov ch,0;RESETEO EL REGISTRO QUE VOY A USAR PARA CONTAR LAS LETRAS
        xor dx,dx;RESETEO EL REGISTRO QUE VOY A USAR PARA CONTAR LOS PUNTOS Y LAS COMAS (DH->PUNTOS,DL->COMAS)
        xor bx,bx;RESETEO EL REGISTRO QUE USO PARA RECORRER EL TEXTO INGRESADO
sigue:  
        cmp texto[bx],24h;CORROBORO SI EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES 24H($) 
        je regToAsciiLetraAux;SI ES CIERTO SIGNIFICA QUE YA RECORRI TODO EL TEXTO, POR LO QUE PUEDO PASAR AL SIG PASO,
                             ;SALTO AUXILIAR PQ SINO ME DA OUTOFRANGE(REGTOASCII1)
        cmp texto[bx],2Eh;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 2EH("." PUNTO) 
        je punto;SI EL CARACTER ES PUNTO SALTA A EL LUGAR DONDE INCREMENTA EL CONTADOR DE PUNTOS
        cmp texto[bx],2Ch ;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 2CH("," COMA) 
        je coma ;SI EL CARACTER ES COMA SALTA A EL LUGAR DONDE INCREMENTA EL CONTADOR DE COMA
        cmp texto[bx],40h;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 40H(A MAYUSCULA) 
        ja casiLetra;SI ES CIERTO, PUEDE LLEGAR A SER LETRA
incrementa:
        inc bx;INCREMENTA BX PARA QUE PASE A EL SIGUIENTE CARACTER DEL TEXTO
        jmp sigue;SALTA ARRIBA PARA HACER TODAS LAS CORROBORACIONES QUE SE LE HICIERON AL CARACTER ANTERIOR
casiLetra:
        cmp texto[bx],5ah;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 5AH(Z MAYUSCULA) 
        jbe esLetra;SI ES CIERTO, SIGNIFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ESTA ENTRE "A" y "Z", POR LO QUE ES UNA LETRA
        cmp texto[bx],60h;SI NO SE DIO EL SALTO DE LA ANTERIOR LINEA SIGNIFICA QUE NO ESTA ENTRE A Y Z.COMPARO EL CARACTER QUE CORRESPONDE
                         ;A ESTA VUELTA CON 60H(CARACTER ANTERIOR A LA "a" MINUSCULA EN LA TABLA ASCII)
        ja  casiMinuscula;SI EL CARACTER ES MAYOR A 60H, SIGNIFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ESTA ENTRE ESTA ENTRE LA "a"
                         ; Y EL ULTIMO CARACTER DE LA TABLA ASCII,POR LO QUE PASA A CORROBORAR SI ESTA ENTRE LA a Y z

casiMinuscula:
        cmp texto[bx],7ah;.COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 7AH (z)
        jbe esLetra;SI ES MENOR O IGUAL, SIGNIFICA QUE EL CARACTER ESTA ENTRE LA a Y LA z, POR LO QUE PASA A INCREMENTAR EN UNO AL CONTADOR
                   ;QUE CORRESPONDE A LAS VOCALES       
        jmp incrementa ;SI NO SE DIO EL SALTO DE LA ANTERIOR LINEA SIGNIFICA QUE NO ESTA ENTRE A Y Z NI ENTRE LA a Y LA z
                        ;NO ES PUNTO, NI COMA, POR LO QUE SALTA AL INCREMENTO DE BX PARA QUE SE CHECKEE EL SIGUIENTE CARACTER    
esLetra:
        cmp texto[bx],41h;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 41H (A)
        je vocal;SI ES VERDADERO, SIGNFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES UNA VOCAL
        cmp texto[bx],45h;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 45H (E)
        je vocal;SI ES VERDADERO, SIGNFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES UNA VOCAL
        cmp texto[bx],49h;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 49H (I)
        je vocal;SI ES VERDADERO, SIGNFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES UNA VOCAL
        cmp texto[bx],4Fh;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 4FH (O)
        je vocal;SI ES VERDADERO, SIGNFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES UNA VOCAL
        cmp texto[bx],55h;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 55H (U)
        je vocal;SI ES VERDADERO, SIGNFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES UNA VOCAL
        cmp texto[bx],61h;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 61H (a)
        je vocal;SI ES VERDADERO, SIGNFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES UNA VOCAL
        cmp texto[bx],65h;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 65H (e)
        je vocal;SI ES VERDADERO, SIGNFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES UNA VOCAL
        cmp texto[bx],69h ;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 69H (i)
        je vocal;SI ES VERDADERO, SIGNFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES UNA VOCAL
        cmp texto[bx],6fh;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 6FH (o)
        je vocal;SI ES VERDADERO, SIGNFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES UNA VOCAL
        cmp texto[bx],75h;COMPARO EL CARACTER QUE CORRESPONDE A ESTA VUELTA CON 75H (u)
        je vocal;SI ES VERDADERO, SIGNFICA QUE EL CARACTER QUE CORRESPONDE A ESTA VUELTA ES UNA VOCAL
        jmp incrementa;SI LLEGA A ESTE PUNTO SIGNIFICA QUE EL CARACTER ES UNA CONSONANTE, COSA QUE NO ME PIDEN CONTAR POR LO QUE PASO A ANALIZAR EL SIGUIENTE CARACTER
regToAsciiLetraAux:;SALTO AUXILIAR PQ SINO ME DA OUTOFRANGE
    jmp regToAsciiLetra
vocal:
        inc ch ;INCREMENTA EL REGISTRO QUE CORRESPONDE AL CONTADOR DE VOCALES
        jmp incrementa
punto:
        inc dh;INCREMENTA EL REGISTRO QUE CORRESPONDE AL CONTADOR DE PUNTOS
        jmp incrementa
coma:   
        inc dl;INCREMENTA EL REGISTRO QUE CORRESPONDE AL CONTADOR DE COMAS
        jmp incrementa

;EN DH CANT PUNTOS, EN DL CANT COMAS, EN CH CANT LETRAS
regToAsciiLetra:
        xor ax,ax
        mov al,ch;cargo en el registro acumulador el valor  convertir
        ;SACO CENTENAS, LE SUMO 30H Y PONGO ESO EN EL PRIMER CARACTER
        mov cl,100
        div cl;ahora que dividi en ah tengo el resto y en al el resultado
        add al,30h
        mov contLetras[0],al
        ;SACO DECENAS, LE SUMO 30H Y PONGO ESO EN EL SEGUNDO CARACTER
        mov al,ah
        xor ah,ah
        mov cl,10
        div cl
        ;tENGO LAS UNIDADES EN RESTO, PONGO ESO EN EL TERCER CARACTER
        add al,30h
        mov contLetras[1],al

        add ah,30h
        mov contLetras[2],ah

        xor ax,ax
        mov al,dh;cargo en el registro acumulador el valor  convertir
        mov cl,100
        div cl;ahora que dividi en ah tengo el resto y en al el resultado
        add al,30h
        mov contPuntos[0],al

        mov al,ah
        xor ah,ah
        mov cl,10
        div cl
        add al,30h
        mov contPuntos[1],al

        add ah,30h
        mov contPuntos[2],ah

        xor ax,ax
        mov al,dl;cargo en el registro acumulador el valor  convertir
        mov cl,100
        div cl;ahora que dividi en ah tengo el resto y en al el resultado
        add al,30h
        mov contComas[0],al

        mov al,ah
        xor ah,ah
        mov cl,10
        div cl
        add al,30h
        mov contComas[1],al

        add ah,30h
        mov contComas[2],ah

sumaDeLosTres:
        add dh,dl
        add dh,ch
        jc mePase;SI LA SUMA DE LOS TRES DA MAS DE 255 (1 byte) IMPRIMO EL ERROR DE QUE ME PASE
regToAsciiTotal:
        xor ax,ax
        mov al,dh;cargo en el registro acumulador el valor  convertir
        mov cl,100
        div cl;ahora que dividi en ah tengo el resto y en al el resultado
        add al,30h
        mov contTotal[0],al

        mov al,ah
        xor ah,ah
        mov cl,10
        div cl
        add al,30h
        mov contTotal[1],al

        add ah,30h
        mov contTotal[2],ah

imprime:
        mov ah, 9h
        mov dx, offset terminoDeContar
        int 21h
        jmp terminar
mePase:
        mov ah,9 
        mov dx, offset pasado
        int 21h
terminar:
        mov ax, 4c00h    ;LLAMO AL SERVICIO 4c00h DE LA INTERRUPCION 21:deseo terminar mi programa
        int 21h          ;TERMINAR LA EJECUCION
     main endp

   end main
