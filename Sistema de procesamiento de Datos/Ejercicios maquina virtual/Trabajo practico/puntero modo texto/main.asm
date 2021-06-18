.MODEL SMALL 
.STACK 100H 
.DATA 
MEN1 DB ' MOUSE NO DETECTADO$' 
.CODE 
MAIN PROC FAR 
    ;Protocolo
    PUSH DS
    SUB AX, AX
    PUSH AX
    MOV AX, @DATA
    MOV DS, AX
    ;Protocolo (End)
    
    ;Inicializacion del mouse (begin)
    CALL INIT_MOUSE
    CMP AX, 00
    JE ERROR
    CALL SHOW_CURSOR
    MOV CX, 320
    MOV DX, 240
    CALL PUT_CURSOR
    jmp exit 
    ;Inicializacion del mouse (end)
ERROR: 
    LEA DX, MEN1
    CALL MENSAJE
    CALL LEE
    JMP SALTE
EXIT:
    CALL LEE
    CALL OCULTA_MOUSE
    CALL RESTAURA
SALTE:
    CALL SAL_DOS
    RET
MAIN ENDP

RESTAURA PROC
    MOV AH,00h
    MOV AL,03h
    int 10h
    ret
RESTAURA ENDP

SAL_DOS PROC
    mov AH,4ch
    INT 21H
    RET
SAL_DOS ENDP

INIT_MOUSE PROC NEAR
    MOV AX, 00h
    INT 33H
    RET
INIT_MOUSE ENDP

OCULTA_MOUSE PROC NEAR
    mov ax,02h
    int 33h
    ret
OCULTA_MOUSE ENDP

SHOW_CURSOR PROC NEAR
    push ax
    mov ax,01h
    int 33h
    pop ax
    ret
SHOW_CURSOR ENDP

PUT_CURSOR PROC NEAR
    PUSH AX
    MOV AX,04H
    INT 33H
    POP AX
    RET
PUT_CURSOR ENDP
    LEE PROC
        PUSH AX
        MOV AH,01
        int 21h
        pop ax
        ret
    LEE ENDP

    MENSAJE PROC
        PUSH AX
        MOV AH,09H
        INT 21H
        POP AX
        RET
    MENSAJE ENDP
END MAIN
