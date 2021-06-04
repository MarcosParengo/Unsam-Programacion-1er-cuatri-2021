.8086
.model small
.stack 100h

.data

  bienvenido db "Bienvenido a mi programa",0dh,0ah, 24h ;0dh retorno de carro,0ah bajada de linea,24h signo pesos
  ingrese db "Ingrese un texto para trabajar",0dh,0ah,24h
  var db 255 dup('$'),0dh,0ah,24h;dup('$') llena de $ el vector

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
        mov ax,dx
carga:  mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        cmp al, 0dh   ;COMPARO LO QUE VINO DE TECLADO CON UN CARACTER DE FINALIZACION,EN ESTE CASO ENTER(0dh)
        je afuera   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO

        mov var[bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx    ;parecido a i++
        jmp carga

afuera:        
        ;CAMBIO LAS VOCALES POR MAYUSCULAS
        mov bx,0

compara:
        cmp var[bx], '$'
        je printar

        cmp var[bx],'a'
        je resta
        cmp var[bx],'e'
        je resta
        cmp var[bx],'i'
        je resta
        cmp var[bx],'o'
        je resta
        cmp var[bx],'u'
        je resta
        inc bx
        jmp compara

resta:  sub var[bx],20h;SUB ES LA INSTRUCCION PARA RESTAR
        inc bx
        jmp compara

printar:mov ah, 9h  ;LLAMO AL SERVICIO 9 DE LA INTERRUPCION 21:IMPRESION DE CADENAS
        mov dx, offset var  ;QUIERO QUE IMPRIMAS A PARTIR DE ACA
        int 21h

        mov ax, 4c00h    ;LLAMO AL SERVICIO 4c00h DE LA INTERRUPCION 21:deseo terminar mi programa
        int 21h          ;TERMINAR LA EJECUCION
     main endp

   end main
