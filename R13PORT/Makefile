vpath %.cpp src
vpath %.h include

CC=g++
bd=build
std=--std=c++11
objc=$(bd)/main.o $(bd)/port.o

prog_name=program


all: $(prog_name)


$(prog_name): $(objc)
	@$(CC) $(std) -o $(prog_name) $(objc)

$(bd)/main.o: main.cpp port.h
	@mkdir -p $(bd)
	@$(CC) $(std) -I include -c $(<) -o $@

$(bd)/port.o: port.cpp port.h
	@mkdir -p $(bd)
	@$(CC) $(std) -I include -c $(<) -o $@

.PHONY: clean

clean:
	@rm -r -f $(bd)
	@rm -f $(prog_name)

