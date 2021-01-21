@echo off
IF %COMPILER%==msvc2019 (
    @echo on
    CALL "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
    mkdir build
    cd build
    cmake .. -DEIGEN3_INSTALL_DIR="c:\%EIGEN3_INSTALL_PATH%"
    msbuild -verbosity:minimal qpp.sln
)
IF %COMPILER%==msys2 (
    @echo on
    SET "PATH=C:\msys64\mingw64\bin;%PATH%"
    cd %APPVEYOR_BUILD_FOLDER%
    mkdir build
    cd build
    bash -lc "cmake .. -DEIGEN3_INSTALL_DIR=/c/%EIGEN3_INSTALL_PATH% -GNinja && ninja"
)
