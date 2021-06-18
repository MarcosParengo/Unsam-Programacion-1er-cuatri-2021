.8086
.model small
.stack 100h

.data

 var db "000", 24h
 yaSalieron db "$$$$$$$$$$"

.code

  main proc
      mov ax, @data
      mov ds, ax
noListo:
      call randNmro
      call waitMiRey
      cmp yaSalieron[7],24h
      je noListo


      mov ax, 4c00h
      int 21h

      main endp

waitMiRey PROC
      mov ah, 2ch ;Tiempo del sistema
      int 21h     ;Ch = hora cl = minutos dh = segundos dl = 1/100 segundos
      add dl,cl
      add dh,dl
      cmp dh,59
      jbe noHaceFalta
      sub dh,59
noHaceFalta:
      mov bh,dh
      push bx
noPasoTiempo:
      mov ah, 2ch ;Tiempo del sistema
      int 21h 
      pop bx  
      cmp bh,dh
      jbe listo
      push bx
      jmp noPasoTiempo
listo:
      ret

waitMiRey ENDP


;Genero un numero random
randNmro PROC

      push ax
      push bx
      push cx

      mov ah, 2ch ;Tiempo del sistema
      int 21h     ;Ch = hora cl = minutos dh = segundos dl = 1/100 segundos

      push dx

      xor ax,ax
      mov al,dl;al dividendo
      mov cl,10;cl divisor
      div cl;ah resto,al resultado
      mov al,ah
      cmp al,8
      jae yaSalio
      add al,30h;sumo 30h para pasar a ascii
      mov si,0
verificoSiYaSalio:
      cmp al,yaSalieron[si]
      je yaSalio
      cmp yaSalieron[si],24h
      je noSalio
      inc si
      jmp verificoSiYaSalio
noSalio:
      mov yaSalieron[si],al
      mov ah,02h;muevo a ah 2 para con la interrupcion 21 imprimir lo guardado en dl caracter
      mov dl,al
      int 21h
yaSalio:
      pop dx
      pop cx
      pop bx
      pop ax
      ret
randNmro ENDP
end main