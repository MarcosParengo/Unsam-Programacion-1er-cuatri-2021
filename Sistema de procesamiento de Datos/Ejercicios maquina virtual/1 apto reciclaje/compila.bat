@ECHO OFF
tasm %1.asm
tasm lib.asm
tlink %1.obj lib.obj
cls
%1.exe
