@echo off

@REM adding gcc cross compiler, binutils & dependencies to path
set path=%cd%\tools\cygwin\lib\gcc\x86_64-pc-cygwin\11;%path%
set path=%cd%\tools\cygwin\bin;%path%
set path=%cd%\tools\i686-elf\bin;%path%

@REM adding external tools to path
set path=%cd%\tools\nasm;%path%
set path=%cd%\tools\qemu;%path%
set path=%cd%\tools\bochs;%path%

@REM add local scripts and tools to system path
set path=%cd%\scripts;%path%
set path=%cd%\tools;%path%

@REM setup MSVC environment
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

if not exist output; mkdir output
if not exist tools; mkdir tools
cd output