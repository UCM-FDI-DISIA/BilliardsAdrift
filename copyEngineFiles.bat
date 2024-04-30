@echo off

rem Directorios
set BAT_DIR=%~dp0
set GAME_BIN=%BAT_DIR%bin\
set ENGINE_BIN=%BAT_DIR%TapiocaEngine\bin\

:parse
if "%~1"=="" goto endparse
if "%~1"=="--nopause" set /a cef_nopause=1
shift
goto parse
:endparse

echo Copiando archivos de motor...
echo %ENGINE_BIN%TapiocaFiles\
xcopy %ENGINE_BIN%TapiocaFiles\ %GAME_BIN%TapiocaFiles\ /q /i /s /r /y
xcopy %ENGINE_BIN%plugins.cfg %GAME_BIN% /r /y
if not defined cef_nopause pause
