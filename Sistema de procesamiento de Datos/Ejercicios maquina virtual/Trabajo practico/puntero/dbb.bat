@ECHO OFF
tasm main.asm
tasm lib.asm
tlink main.obj lib.obj
cls
td main.exe