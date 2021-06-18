.8086
.model small
.stack 100
.data

 archivo db "algo.txt", "$"
 filehandler db 00h,00h
 readchar db 20h
 filerror db "Archivo no existe o error de apertura", 0dh, 0ah, '$'
 charactererror db "Error de lectura de caracter", 0dh, 0ah, '$'
 nextpage db "Presione <Enter> para seguir, otra tecla para salir...", "$"
 currentline db 01h

.code
main proc

  mov ax,@data
  mov ds,ax
  
  call Clearscreen

  lea dx,archivo
  mov ah,3dH
  mov al,0
  int 21H
  jc openerr
  mov word ptr[filehandler], ax
char:
  mov ah,3FH
  mov bx, word ptr [filehandler]
  mov cx,1
  lea dx,readchar
  int 21H
  jc charerr
  cmp ax,0
  je eof
  mov dl,readchar
  mov ah,02H
  int 21H 
  cmp dl,0ah
  jne char
  cmp currentline,18h
  je endofpage
  inc currentline
  jmp char
endofpage:
  lea dx, nextpage
  mov ah,9
  int 21h
  mov ah,1
  int 21h
  cmp al,0dh
  jne final
  mov currentline,01h
  call Clearscreen
  jmp char
 openerr:
  lea dx, filerror
  mov ah,9
  int 21h
  jmp final
 charerr:
  lea dx, charactererror
  mov ah,9
  int 21h
  jmp final
final:
eof:
	mov ah,4ch
	int 21H
main endp
Clearscreen proc 
	push ax
	push es
	push cx
	push di
	mov ax,3
	int 10h
	mov ax,0b800h
	mov es,ax
	mov cx,1000
	mov ax,7
	mov di,ax
	cld
	rep stosw
	pop di
	pop cx
	pop es
	pop ax
	ret 
Clearscreen endp
end main