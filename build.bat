@echo off
setlocal enabledelayedexpansion
set "FILES="
for %%F in (Problem2\*.cpp) do (
	set "FILES=!FILES! \"%%F\""
)
"C:\msys64\ucrt64\bin\g++.exe" -fdiagnostics-color=always -g %FILES% -o "Problem2\main.exe"
endlocal
