@echo off

:: Compilamos el motor
cd .\SplashShowdownSol\Quack-Engine
call QuackEngine.bat


:: Compilamos la solucion en debug y release
cd ..\..
msbuild "Splash-Showdown.sln" /p:configuration=Debug
msbuild "Splash-Showdown.sln" /p:configuration=Release

pause