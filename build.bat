@echo off

call %~dp0updateAndBuildEngine.bat --nodeb --nopause


set BAT_DIR=%~dp0
set BUILD_DIR=%BAT_DIR%build\
set ENGINE_BIN=%BAT_DIR%TapiocaEngine\bin\
set GAME_BIN=%BAT_DIR%bin\

echo %ENGINE_BIN%TapiocaFiles\
xcopy %ENGINE_BIN%TapiocaFiles\ %BUILD_DIR%TapiocaFiles\ /q /i /s /r /y
xcopy %ENGINE_BIN%plugins.cfg %BUILD_DIR% /r /y
echo %ENGINE_BIN%*.dll
xcopy %ENGINE_BIN%*.dll %BUILD_DIR% /q /i /r /y /exclude:_d.dll
xcopy %ENGINE_BIN%Main.exe %BUILD_DIR% /r /y
echo %GAME_BIN%assets\
xcopy %GAME_BIN%assets\ %BUILD_DIR%assets\ /q /i /s /r /y
pause
