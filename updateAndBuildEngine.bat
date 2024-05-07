@echo off
git submodule init
git submodule update --init --recursive --remote

set BAT_DIR=%~dp0
set TAPIOCA_ENGINE_DIR=%BAT_DIR%TapiocaEngine\

:parse
if "%~1"=="" goto endparse
if "%~1"=="--nodeb" set /a ube_nodeb=1
if "%~1"=="--norel" set /a ube_norel=1
if "%~1"=="--nopause" set /a ube_nopause=1
shift
goto parse
:endparse

if defined ube_nodeb (
if defined ube_norel (
call %TAPIOCA_ENGINE_DIR%buildEngine.bat --nodeb --norel --nopause
) else (
call %TAPIOCA_ENGINE_DIR%buildEngine.bat --nodeb --nopause
)
) else if defined ube_norel (
call %TAPIOCA_ENGINE_DIR%buildEngine.bat --norel --nopause
) else call %TAPIOCA_ENGINE_DIR%buildEngine.bat --nopause
call %~dp0copyEngineFiles.bat --nopause

if not defined ube_nopause pause