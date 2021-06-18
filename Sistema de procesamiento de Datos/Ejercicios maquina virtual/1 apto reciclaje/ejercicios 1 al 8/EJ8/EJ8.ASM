.8086
.model small
.stack 100h
.data
;Pretendo ingresar texto e imprimirlo al revez
  bienvenido db "Bienvenido a mi programa",0dh,0ah, 24h ;0dh retorno de carro,0ah bajada de linea,24h signo pesos
  ingrese db "Ingrese un texto para que el programa lo encripte",0dh,0ah,24h
 
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
        mov cx,0
carga:  
        cmp bx, 255; ;Si se ingresaron 5 letras ya se va para afuera
        je afuera   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        cmp al,0dh
        je afuera

        mov texto[bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx    ;parecido a i++
        inc cx
        jmp carga 
afuera:
        mov bx,0  ;BX registro base, se puede mover por la ram, es como la variable i;Le asigno 0
sigue:  
        cmp bx,cx
        je finCompara

        add texto[bx],5h
        inc bx
        jmp sigue

finCompara:    
        mov ah,9
        mov dx, offset texto
        int 21h
        jmp terminar

terminar:
        mov ax, 4c00h    ;LLAMO AL SERVICIO 4c00h DE LA INTERRUPCION 21:deseo terminar mi programa
        int 21h          ;TERMINAR LA EJECUCION
     main endp

   end main
