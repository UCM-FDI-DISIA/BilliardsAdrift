@echo off

REM Este archivo deberia ir a la misma altura que el .sln de los juegos

set BAT_DIR=%~dp0
set PARENT_DIR=%BAT_DIR%..\

set LNK_NAME=TapiocaEngine
set LNK_DIR=%BAT_DIR%%LNK_NAME%\

echo %PARENT_DIR%%LNK_NAME%

if exist %LNK_DIR% (
    echo %LNK_DIR% ya existe, eliminando
    rmdir %LNK_DIR%
)
echo Creando enlace a %LNK_NAME% en %LNK_DIR%

mklink /D %BAT_DIR%%LNK_NAME% %PARENT_DIR%%LNK_NAME%
if errorlevel 1 (
    echo Error al crear enlace con el motor
) else (
    echo Enlace con el motor creado correctamente
	call %BAT_DIR%copyEngineFiles.bat --nopause
)


pause