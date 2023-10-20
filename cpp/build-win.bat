@echo off
setlocal EnableDelayedExpansion

set root_path=%~dp0
cd %root_path%

:: cmake (Debug/Release)
set config=Debug
set install_path=install\%config%
echo config: %config%
echo install_path: %install_path%
echo "cmake -B build -S . -DCMAKE_INSTALL_PREFIX=%install_path%"
cmake -B build -S . -DCMAKE_INSTALL_PREFIX=%install_path%
echo "cmake --build build --target install --config %config%"
cmake --build build --target install --config %config%

:: run (main & test)
echo "%install_path%\bin\sample-main.exe"
%install_path%\bin\sample-main.exe
