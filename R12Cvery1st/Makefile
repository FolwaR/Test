#Generated by makefilegenerator.py
#autor: Lukasz Folwarczyk

vpath %.cpp src
vpath %.h include

bd=build
CC=g++
std=c++11
prog_name=program

.PHONY: all

all: $(prog_name)

$(prog_name): $(bd)/Cow.o $(bd)/R12Cvery1st.o 
	@$(CC) --std=$(std) $(^) -o $(@)
	@echo 'Wygenerowano plik Makefile ;)'


$(bd)/Cow.o: Cow.cpp
	@mkdir -p $(bd)
	@$(CC) --std=$(std) -I include -c $(<) -o $(@)

$(bd)/R12Cvery1st.o: R12Cvery1st.cpp
	@mkdir -p $(bd)
	@$(CC) --std=$(std) -I include -c $(<) -o $(@)

.PHONY: clean
clean:
	@echo "Usówam program ..."
	@rm -r -f $(bd)
	@rm -f $(prog_name)
	@echo "Program usunięty"

