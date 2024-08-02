@echo off

cd ..

rem ======================================================================
mkdir dist 2> nul
mkdir dist\include\Sigma 2> nul
mkdir dist\dependencies 2> nul
mkdir dist\bin 2> nul
mkdir dist\bin\Debug 2> nul
mkdir dist\bin\Release 2> nul

rem ======================================================================
echo Building project ...

echo:
echo DEBUG
make config=debug Sigma

echo:
echo RELEASE
make config=release Sigma

rem ======================================================================
echo:
echo Copying project files ...
xcopy Sigma\src dist\include\Sigma /e /y > nul
for /r "dist\include\Sigma" %%x in (*.cpp) do del "%%x" > nul

copy /y bin\Debug-x86_64\Sigma\Sigma.dll dist\bin\Debug > nul
copy /y bin\Release-x86_64\Sigma\Sigma.dll dist\bin\Release > nul

rem ======================================================================
echo:
echo Copying dependencies files ...
xcopy Libraries\entt\include dist\dependencies /e /y > nul
xcopy Libraries\stb_image\include dist\dependencies /e /y > nul
xcopy Libraries\spdlog\spdlog\include dist\dependencies /e /y > nul
xcopy Libraries\glad\include dist\dependencies /e /y > nul
xcopy Libraries\glfw\glfw\include dist\dependencies /e /y > nul
xcopy Libraries\glm\include dist\dependencies /e /y > nul

PAUSE