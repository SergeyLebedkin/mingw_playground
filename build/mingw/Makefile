all: link
	call build/mingw/prep.bat

link: compile
	g++ -g .out/src/main.o -o main

compile: 
	g++ -g -c src/main.cpp -o .out/src/main.o

clean:
	del /q ..\..\.out\src\*.o