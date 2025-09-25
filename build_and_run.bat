@echo off
setlocal enabledelayedexpansion

set BUILD_DIR=build
set WX_ROOT=C:\wxWidgets-3.3.1
set WX_LIB_DIR=%WX_ROOT%\build-mingw\lib\gcc_x64_dll
set WX_CONFIG=%WX_ROOT%\build-mingw\wx-config
set WX_INCLUDE="%WX_ROOT%/include;%WX_ROOT%/build-mingw/lib/gcc_x64_dll/mswud"

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

cmake -S . -B "%BUILD_DIR%" ^
  -DwxWidgets_ROOT_DIR="%WX_ROOT%" ^
  -DwxWidgets_LIB_DIR="%WX_LIB_DIR%" ^
  -DwxWidgets_CONFIGURATION=mswud ^
  -DwxWidgets_INCLUDE_DIRS=%WX_INCLUDE% ^
  -DwxWidgets_CONFIG_EXECUTABLE="%WX_CONFIG%"
if errorlevel 1 goto :error

cmake --build "%BUILD_DIR%"
if errorlevel 1 goto :error

pushd "%BUILD_DIR%"
if exist pixelshop.exe (
  pixelshop.exe
) else (
  echo pixelshop.exe not found in %CD%
)
popd

echo.
echo Build and run completed successfully.
goto :eof

:error
echo.
echo Build failed. See the messages above for details.
exit /b 1
