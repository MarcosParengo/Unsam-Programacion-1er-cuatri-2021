.8086
.model small
.stack 100h
.data
  simb db " ",24h
  linea db 0dh,0ah
  linea2 db 80 dup (04h),24h
.code
extrn Clearscreen:proc
main proc

  mov ax, @data
  mov ds, ax

  call Clearscreen
  call initGraphics ;Entra al modo grafico y muestra el cursor
  
  xor ah, ah    ;Espera a que se toque una tecla (No importa cual) 
                ;Para pasar al modo de texto y finalizar el programa
  int 16h

  call finalizeGraphics
 
fin:
  mov ax, 4c00h
  int 21h
main endp

   ;Set graphic mode, reset mouse and show cursor
 initGraphics:
    push es

    mov ax, 13h
    int 10h

    push 0a000h
    pop es 
    xor di, di 
    mov ax, 0909h
    mov cx, 320*200/2 
    rep stosw 
    
    ;Show cursor
    mov ax, 01h 
    int 33h

    ;Set cursor horizontal limits
    mov ax,07h
    mov cx,0;minimo horizontal (0)
    mov dx,639;Maximo horizontal (640)
    int 33h

    ;Set cursor vertical limits
    mov ax,08h
    mov cx,0;minimo horizontal (0)
    mov dx,199;Maximo horizontal (640)
    int 33h

    pop es
    ret

 ;Hide cursor and set text mode
 finalizeGraphics:
    mov ax, 02h
    int 33h 

    mov ax, 03h 
    int 10h 

    ret 

 ;Set cursor
 ;Hotspot X
 ;Hotspot Y
 ;Ptr to cursor bitmaps
 setCursor:
    push bp 
    mov bp, sp
    push dx
    push cx
    push bx
    push ax
    push es

    mov ax, 09h
    mov bx, WORD PTR [bp+08h]
    mov cx, WORD PTR [bp+06h]
    mov dx, WORD PTR [bp+04h]
    push ds                         ;Setting ES = DS is not necessary in COM
    pop es                          ;files unless somebody changed ES
    int 33h 

    pop es
    pop ax
    pop bx 
    pop cx
    pop dx

    pop bp  
    ret 06h     


    ;
    ; CURSORS
    ;

end main
