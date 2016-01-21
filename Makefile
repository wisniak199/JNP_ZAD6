CC = g++
CFLAGS = -Wall -std=c++11 -c
LDFLAGS = -Wall -std=c++11
ALL = account bank_system gsb planet 

all: gsb

gsb: gsb.o planet.o bank_system.o account.o
	$(CC) $(LDFLAGS) -o gsb gsb.o planet.o bank_system.o account.o

planet.o: planet.cpp
	$(CC) $(CFLAGS) -o planet.o planet.cpp

gsb.o: gsb.cpp
	$(CC) $(CFLAGS) -o gsb.o gsb.cpp

bank_system.o: bank_system.cpp
	$(CC) $(CFLAGS) -o bank_system.o bank_system.cpp

account.o: account.cpp
	$(CC) $(CFLAGS) -o account.o account.cpp
clean:
	rm -f *.o $(ALL) *~
