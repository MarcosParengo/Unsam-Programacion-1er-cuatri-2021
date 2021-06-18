@ECHO OFF
tasm int80
tlink /t int80
int80
tasm %1.asm
tasm lib.asm
tlink %1.obj lib.obj
cls
%1.exe
