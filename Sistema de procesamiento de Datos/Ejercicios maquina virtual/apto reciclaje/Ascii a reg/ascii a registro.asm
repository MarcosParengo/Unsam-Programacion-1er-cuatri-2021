.8086
.model small
.stack 100h
.data
;Pretendo ingresar texto e imprimirlo al revez
  bienvenido db "Bienvenido a mi programa",0dh,0ah, 24h ;0dh retorno de carro,0ah bajada de linea,24h signo pesos
  ingrese db "Ingrese un texto para que el programa lo encripte",0dh,0ah,24h
 
  nro db "064",0dh,0ah,24h

.code
     main proc
        mov ax, @data   ;INICIALIZO EL DATA SEGMENT
        mov ds, ax

        xor dx,dx

        mov al,nro[0]
        sub al,30h
        mov cl,100
        mul cl
        add dl,al

        mov al,nro[1]
        sub al,30h
        mov cl,10
        mul cl
        add dl,al

        mov al,nro[2]
        sub al,30h
        add dl,al

        mov ax, 4c00h    ;LLAMO AL SERVICIO 4c00h DE LA INTERRUPCION 21:deseo terminar mi programa
        int 21h          ;TERMINAR LA EJECUCION
     main endp

   end main
