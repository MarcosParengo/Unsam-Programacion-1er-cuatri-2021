@ECHO OFF
tasm %1.asm
tasm lib.asm
tlink %1.obj lib.obj
%1.exe