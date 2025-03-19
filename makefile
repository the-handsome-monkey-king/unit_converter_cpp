# makefile
#
# @author Ryan Morehouse
# @license GNU3
#
# compiled on a raspberry pi running gcc 7.1, so 
# disabled warnings for 6 & earlier compiler warnings
#
#

OBJ = Volume.o CurrencyExchangeRates.o Temperature.o UnitConverter.o test.o
DEPS = Volume.o CurrencyExchangeRates.o Temperature.o UnitConverter.o
FLAGS = -Wall -Wno-psabi
CC = g++
.SUFFIXES: .cpp .o

.cpp.o:
	g++ -o $@ $^ $(FLAGS)

all: $(OBJ)

CurrencyExchangeRates.o: CurrencyExchangeRates.cpp 
	$(CC) -c -o $@ $^ $(FLAGS)

Volume.o: Volume.cpp 
	$(CC) -c -o $@ $^ $(FLAGS)

Temperature.o: Temperature.cpp 
	$(CC) -c -o $@ $^ $(FLAGS)

UnitConverter.o: UnitConverter.cpp
	$(CC) -c -o $@ $^ $(FLAGS)

test.o: test.cpp $(DEPS)

clean:
	\rm -f *.o
