# Makefile du projet CPP

.SILENT:

OBJECTS = Event.o Test1.o

PROGRAMS = Test1 

all: $(PROGRAMS)

Test1 : Test1.o Event.o
	g++ -o Test1 Event.o Test1.o

Test1.o : Test1.cpp
	echo Compilation du Test1
	g++ -c -o Test1.o Test1.cpp -D DEBUG

Event.o : Classes/Event.cpp Classes/Event.h
	g++ -c -o Event.o Classes/Event.cpp -D DEBUG


clean:
	rm -f $(OBJECTS) $(PROGRAMS)