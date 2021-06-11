.8086
.model small
.stack 100h
.data
;Pretendo ingresar texto e imprimirlo al revez
  bienvenido db "Bienvenido a mi programa",0dh,0ah, 24h ;0dh retorno de carro,0ah bajada de linea,24h signo pesos
  ingrese db "Ingrese un texto para que el programa lo encripte",0dh,0ah,24h
 
  nro db "000",0dh,0ah,24h

.code
     main proc
        mov ax, @data   ;INICIALIZO EL DATA SEGMENT
        mov ds, ax

        mov cl,126

        xor ax,ax
        mov al,cl;cargo en el registro acumulador el valor  convertir
        mov cl,100
        div cl;ahora que dividi en ah tengo el resto y en al el resultado
        add al,30h
        mov nro[0],al

        mov al,ah
        xor ah,ah
        mov cl,10
        div cl
        add al,30h
        mov nro[1],al

        add ah,30h
        mov nro[2],ah

        mov ah,9
        mov dx,offset nro
        int 21h

        mov ax, 4c00h    ;LLAMO AL SERVICIO 4c00h DE LA INTERRUPCION 21:deseo terminar mi programa
        int 21h          ;TERMINAR LA EJECUCION
     main endp

   end main
