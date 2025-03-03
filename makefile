# makefile
#
# @author Ryan Morehouse
# @license GNU3
#
# compiled on a raspberry pi running gcc 7.1, so 
# disabled warnings for 6 & earlier compiler warnings

OBJ = Currency.o UnitConverter.o test.o test_currency.o
DEPS = Currency.o UnitConverter.o
FLAGS = -Wall -Wno-psabi
CC = g++
.SUFFIXES: .cpp .o

.cpp.o:
	g++ -o $@ $^ $(FLAGS)

all: $(OBJ)

UnitConverter.o: UnitConverter.cpp
	$(CC) -c -o $@ $< $(FLAGS)

Currency.o: Currency.cpp
	$(CC) -c -o $@ $< $(FLAGS)

test.o: test.cpp $(DEPS)

test_currency.o: test_currency.cpp $(DEPS)

clean:
	\rm -f *.o
