@echo off

rem BAT_DIR=%~dp0
call %~dp0updateAndBuildEngine.bat --nodeb --nopause

set BAT_DIR=%~dp0
set BUILD_DIR=%BAT_DIR%build\
set GAME_BIN=%BAT_DIR%bin\


xcopy %ENGINE_BIN%TapiocaFiles\ %BUILD_DIR%TapiocaFiles\ /q /i /s /r /y
xcopy %ENGINE_BIN%plugins.cfg %GAME_BIN% /r /y
pause
