#define a compiler (name it CC)
CC = C++
HEADERS =  Common.h Dealer.h Deck.h Game.h Participant.h Player.h
SOURCES = Dealer.cpp Deck.cpp Game.cpp Participant.cpp Player.cpp main.cpp 
OBJECTS = $(SOURCES:.C=.o)
LDLIBS  = -lm 
#FLAGS   = -Wall 
#FLAGS   = -Wall   -funroll-loops  -O4


# Pattern rule
%.o : %.C $(HEADERS)
	$(CC) -c  $<

blackJack :  $(SOURCES)
	$(CC) $(SOURCES) -o blackJack $(LDLIBS) ${FLAGS}


clean :
	rm -f *.o  blackJack

