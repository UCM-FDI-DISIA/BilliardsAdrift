@echo off
git submodule init
git submodule update --remote

set BAT_DIR=%~dp0
set TAPIOCA_ENGINE_DIR=%BAT_DIR%TapiocaEngine\

call %TAPIOCA_ENGINE_DIR%buildEngine.bat
