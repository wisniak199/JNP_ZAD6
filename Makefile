CC = clang++
CFLAGS = -Wall -std=c++11 -c
LDFLAGS = -Wall -std=c++11
ALL = account bank_system gsb planet bank_builder gkb bank interstellarclock currency

all: gsb

gsb: gsb.o planet.o bank_system.o account.o bank_builder.o bank.o interstellarclock.o currency.o
	$(CC) $(LDFLAGS) -o gsb gsb.o planet.o bank_system.o bank.o account.o bank_builder.o interstellarclock.o currency.o

planet.o: planet.cpp
	$(CC) $(CFLAGS) -o planet.o planet.cpp

gsb.o: gsb.cpp
	$(CC) $(CFLAGS) -o gsb.o gsb.cpp

bank_system.o: bank_system.cpp
	$(CC) $(CFLAGS) -o bank_system.o bank_system.cpp

bank.o: bank.cpp
	$(CC) $(CFLAGS) -o bank.o bank.cpp

account.o: account.cpp
	$(CC) $(CFLAGS) -o account.o account.cpp

bank_builder.o: bank_builder.cpp
	$(CC) $(CFLAGS) -o bank_builder.o bank_builder.cpp

interstellarclock.o: interstellarclock.cpp
	$(CC) $(CFLAGS) -o interstellarclock.o interstellarclock.cpp

currency.o: currency.cpp
	$(CC) $(CFLAGS) -o currency.o currency.cpp

clean:
	rm -f *.o $(ALL) *~
