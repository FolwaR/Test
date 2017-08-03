
vpath %.cpp src
vpath %.h include

CC=g++
std=--std=c++11
all: program
bd=build
objc=$(bd)/R13DNA.o $(bd)/DNA.o

prog_name=program


$(prog_name): $(objc)
	$(CC) $(std) -o $(prog_name) $(objc)

$(bd)/DNA.o: DNA.cpp DNA.h
	mkdir -p $(bd)		
	$(CC) -I include -c $(<) -o $(@)

$(bd)/R13DNA.o: R13DNA.cpp DNA.h
	mkdir -p $(bd)
	$(CC) -I include -c $(<) -o $(@)

.PHONY: clean

clean:
	rm -r -f build
	rm $(prog_name)

