.8086
.model small
.stack 100h
.data
;Pretendo ingresar texto e imprimirlo al revez
  bienvenido db "Bienvenido a mi programa",0dh,0ah, 24h ;0dh retorno de carro,0ah bajada de linea,24h signo pesos
  ingrese db "Ingrese un texto para que el programa determine si es o no palindromo",0dh,0ah,24h
 
  cartel1 db 0dh,0ah,"Palindromo",0dh,0ah,24h
  cartel2 db 0dh,0ah,"no palindromo",0dh,0ah,24h
  texto db 255 dup (20h),0dh,0ah,24h

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
        cmp bx, 255; ;Si se ingresaron 5 letras ya se va para afuera
        je compara   ;SI LA COMPARACION DEVUELVE 1,SALTA A AFUERA Y CORTA EL CICLO
        mov ah, 1   ;LLAMO AL SERVICIO 1 DE LA INTERRUPCION 21:LECTURA
        int 21h
        cmp al,0dh
        je compara

        mov texto[bx],al    ;guardo el ascii de la letra que viene en al dentro de la variable el la posicion bx
        inc bx    ;parecido a i++
        jmp carga 
compara:
        dec bx
        mov si,0
sigue:  
        cmp texto[si],20h
        je incs
        cmp texto[bx],20h
        je incb

        cmp si,bx
        jg finCompara
        mov al, texto[bx]
        cmp texto[si],al
        jne error
        inc si
        dec bx
        jmp sigue

incs:
        inc si
        jmp sigue

incb:
        dec bx
        jmp sigue

finCompara:    
        mov ah,9
        mov dx, offset cartel1
        int 21h
        jmp terminar
error:    
        mov ah,9
        mov dx, offset cartel2
        int 21h

terminar:
        mov ax, 4c00h    ;LLAMO AL SERVICIO 4c00h DE LA INTERRUPCION 21:deseo terminar mi programa
        int 21h          ;TERMINAR LA EJECUCION
     main endp

   end main
