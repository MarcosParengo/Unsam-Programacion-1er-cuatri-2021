.8086
.model small
.stack 100h
.data
;Jump out of range
  bienvenido db "Bienvenido a mi programa",0dh,0ah, 24h ;0dh retorno de carro,0ah bajada de linea,24h signo pesos
  menu db "Que operacion desea realizar (1.Suma 2.Resta 3.Multiplicacion 4.Division)?",0dh,0ah,24h
  ingresonumero1 db 0dh,0ah,"Ingrese el primer numero de tres digitos para la operacion (Tenga en cuenta que si quiere ingresar 10 deberia ingresar 010)",0dh,0ah,24h
  ingresonumero2 db 0dh,0ah,"Ingrese el segundo numero de tres digitos para la operacion (Tenga en cuenta que si quiere ingresar 10 deberia ingresar 010)",0dh,0ah,24h
  error db 0dh,0ah,"La opcion introducida no es valida, vuelva a intentarlo",0dh,0ah,24h
  resultado1 db 0dh,0ah,"El resultado de su operacion (",24h
  resultado2 db ") es: ",24h
  errorMePase db 0dh,0ah,"ERROR: Su resultado es mayor a 255, esta calculadora no es capaz de procesarlo",24h
  errorDivision db 0dh,0ah,"ERROR: No puede dividir por 0",24h
  salto db 0dh,0ah

  operacion db 2 dup (24h)
  numero1 db "000",24h
  numero2 db "000",24h 
  negativo db "-"
  resultado db "000",24h

.code
     main proc
        mov ax, @data   ;INICIALIZO EL DATA SEGMENT
        mov ds, ax

        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset bienvenido ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h

seleccion: 
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset menu  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h      
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        cmp al,30h; 
        ja casi;
        jmp descartado;

casi:
        cmp al,34h; 
        jbe opcionCorrecta;

descartado:
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset error  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h  
        jmp seleccion;no metio ninguna de las opciones pedidas 

opcionCorrecta:
        mov operacion[0],al
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset ingresonumero1  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h       
        mov bx,0
cargaNumero1:  
        cmp bx, 3; ;Si se ingresaron 3 numeros se va para afuera
        je siguiente   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        cmp al,0dh
        je siguiente
        mov numero1[bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx    ;parecido a i++
        jmp cargaNumero1
siguiente:
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset ingresonumero2  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h
        mov bx,0
cargaNumero2:  
        cmp bx, 3; ;Si se ingresaron 3 numeros se va para afuera
        je afuera   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        cmp al,0dh
        je afuera
        mov numero2[bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx    ;parecido a i++
        jmp cargaNumero2
afuera: ;asciitoreg
        mov cl,0
        mov dl,0
        mov dh,0
        xor ax,ax

        mov al,numero1[0]
        sub al,30h
        mov cl,100
        mul cl
        add dl,al
        mov al,numero1[1]
        sub al,30h
        mov cl,10
        mul cl
        add dl,al
        mov al,numero1[2]
        sub al,30h
        add dl,al

        mov cl,0
        xor ax,ax

        mov al,numero2[0]
        sub al,30h
        mov cl,100
        mul cl
        add dh,al
        mov al,numero2[1]
        sub al,30h
        mov cl,10
        mul cl
        add dh,al
        mov al,numero2[2]
        sub al,30h
        add dh,al
;Tengo en dl mi numero1 y en dh mi numero2
        xor cx,cx
        xor ax,ax
        cmp operacion, 31h
        je suma
        cmp operacion, 32h
        je resta
        cmp operacion, 33h
        je multiplicacion
        cmp operacion, 34h
        je division
suma:
        mov operacion[0],2bh
        mov al,dl
        add al,dh
        jc mePase
        jmp regToAscii
        ;en al tengo mi resultado;
resta: ;lista
        mov operacion[0],2dh
        mov al,dl
        sub al,dh
        cmp al,0
        jge regToAscii

        mov bl,1;Flag
        neg al
        jmp regToAscii
        ;en al tengo mi resultado;
multiplicacion:;lista
        mov operacion[0],2ah
        mov al,dl
        mov cl,dh
        mul cl

        cmp ah,0
        jg mePase;el resultado de la operacion no entra en un byte

        jmp regToAscii
        ;en al tengo mi resultado;
division:;lista
        mov operacion[0],2fh
        cmp dh,0
        je eDivision

        xor ax,ax
        mov al,dl
        mov cl,dh
        div cl
        jmp regToAscii
        ;en al tengo mi resultado;
regToAscii:
        ;el valor a convertir ya esta en al
        mov ah,0
        mov cl,100
        div cl;ahora que dividi en ah tengo el resto y en al el resultado
        add al,30h
        mov resultado[0],al

        mov al,ah
        xor ah,ah
        mov cl,10
        div cl
        add al,30h
        mov resultado[1],al

        add ah,30h
        mov resultado[2],ah
        jmp fin
eDivision:
        mov ah, 9h
        mov dx, offset errorDivision
        int 21h  
        jmp terminar        
mePase:
        mov ah, 9h
        mov dx, offset errorMePase
        int 21h  
        jmp terminar

fin:
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset resultado1  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h  
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset numero1  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h  
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset operacion  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h  
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset numero2  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h  
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset resultado2  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h 

        cmp bx,1
        je impNeg

        mov ah, 9h
        mov dx, offset resultado
        int 21h
        jmp terminar
impNeg:
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset negativo  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h
terminar:
        mov ax, 4c00h    ;LLAMO AL SERVICIO 4c00h DE LA INTERRUPCION 21:deseo terminar mi programa
        int 21h          ;TERMINAR LA EJECUCION
     main endp

   end main
