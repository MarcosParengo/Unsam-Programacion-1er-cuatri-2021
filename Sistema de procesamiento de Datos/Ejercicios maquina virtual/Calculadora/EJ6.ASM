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
  salto db 0dh,0ah

  operacion db 2 dup (24h)
  numero1 db "000",0dh,0ah,24h
  numero2 db "000",0dh,0ah,24h

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
afuera: 
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset numero1  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h
        mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset numero2  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h
AsciiToReg:
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
        cmp operacion, 30h
        je suma
        cmp operacion, 32h
        je resta
        cmp operacion, 31h
        je multiplicacion
        cmp operacion, 34h
        je division
suma:
        mov ah,dh
        add dl,al
        ;en al tengo mi resultado;
resta:
        mov al,dl
        sub al,dh
        ;en al tengo mi resultado;
multiplicacion:
        mov al,dl
        mov cl,dh
        mul cl
        ;en al tengo mi resultado;
division:
        xor ax,ax
        mov al,dl
        mov cl,dh
        div cl
        ;en al tengo mi resultado;
terminar:
        mov ax, 4c00h    ;LLAMO AL SERVICIO 4c00h DE LA INTERRUPCION 21:deseo terminar mi programa
        int 21h          ;TERMINAR LA EJECUCION
     main endp

   end main
