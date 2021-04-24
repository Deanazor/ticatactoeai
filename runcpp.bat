@echo off&&cls
set /p file=Enter The Name of the file you want to compile:%=%
g++ -o %file% %file%.cpp
%file%.exe