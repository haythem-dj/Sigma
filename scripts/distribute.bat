@echo off

cd ..

rem ======================================================================
mkdir dist 2> nul
mkdir dist\Sigma 2> nul
mkdir dist\Sigma\include\Sigma 2> nul
mkdir dist\Sigma\dependencies 2> nul
mkdir dist\Sigma\bin 2> nul
mkdir dist\Sigma\bin\Debug 2> nul
mkdir dist\Sigma\bin\Release 2> nul
mkdir dist\Sigma\lib
mkdir dist\Sigma\lib\Debug 2> nul
mkdir dist\Sigma\lib\Release 2> nul

rem ======================================================================
echo Building project ...

echo:
echo DEBUG
make CC=gcc config=debug Sigma

echo:
echo RELEASE
make CC=gcc config=release Sigma

rem ======================================================================
echo:
echo Copying project files ...
xcopy Sigma\src dist\Sigma\include\Sigma /e /y > nul
for /r "dist\Sigma\include\Sigma" %%x in (*.cpp) do del "%%x" > nul

copy /y bin\Debug-x86_64\Sigma\Sigma.dll dist\Sigma\bin\Debug > nul
copy /y bin\Release-x86_64\Sigma\Sigma.dll dist\Sigma\bin\Release > nul

copy /y bin\Debug-x86_64\Sigma\Sigma.lib dist\Sigma\lib\Debug > nul
copy /y bin\Release-x86_64\Sigma\Sigma.lib dist\Sigma\lib\Release > nul

rem ======================================================================
echo:
echo Copying dependencies files ...
xcopy Libraries\entt\include dist\Sigma\dependencies /e /y > nul
xcopy Libraries\stb_image\include dist\Sigma\dependencies /e /y > nul
xcopy Libraries\spdlog\spdlog\include dist\Sigma\dependencies /e /y > nul
xcopy Libraries\glad\include dist\Sigma\dependencies /e /y > nul
xcopy Libraries\glfw\glfw\include dist\Sigma\dependencies /e /y > nul
xcopy Libraries\glm\include dist\Sigma\dependencies /e /y > nul

7z a Sigma.zip .\dist\Sigma > nul

PAUSE