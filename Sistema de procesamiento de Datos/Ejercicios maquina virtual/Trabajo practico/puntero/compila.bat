@ECHO OFF
tasm int80
tlink /t int80
int80
tasm main.asm
tasm lib.asm
tlink main.obj lib.obj
main.exe
