@echo off

call %~dp0updateAndBuildEngine.bat --nodeb --nopause
msbuild %~dp0BilliardsAdrift.sln /p:configuration=Release /p:Platform=x64 /p:PlatformToolset=v143

set BAT_DIR=%~dp0
set BUILD_DIR=%BAT_DIR%build\
set ENGINE_BIN=%BAT_DIR%TapiocaEngine\bin\
set GAME_BIN=%BAT_DIR%bin\

echo %ENGINE_BIN%TapiocaFiles\
xcopy %ENGINE_BIN%TapiocaFiles\ %BUILD_DIR%TapiocaFiles\ /q /i /s /r /y
xcopy %ENGINE_BIN%plugins.cfg %BUILD_DIR% /r /y

rem Para copiar los dlls se crea un archivo temporal
echo _d.dll > %BUILD_DIR%exclude.txt
echo %ENGINE_BIN%*.dll
xcopy %ENGINE_BIN%*.dll %BUILD_DIR% /q /i /r /y /exclude:%BUILD_DIR%exclude.txt
del %BUILD_DIR%exclude.txt

xcopy %ENGINE_BIN%Main.exe %BUILD_DIR% /r /y
echo %GAME_BIN%assets\
xcopy %GAME_BIN%assets\ %BUILD_DIR%assets\ /q /i /s /r /y
xcopy %GAME_BIN%game.dll /r /y
pause
