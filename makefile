# Makefile du projet CPP

.SILENT:

OBJECTS = Event.o Test1.o #Test2.o Test3.o Test4.o Test5.o Test6.o Test7.o Test8a.o Test8b.o

PROGRAMS = Test1 #Test2 Test3 Test4 Test5 Test6 Test7 Test8a Test8b

all: $(PROGRAMS)

Test1 : Test1.o Event.o
	g++ -o Test1 Event.o Test1.o

Test1.o : Test1.cpp
	echo Compilation du Test1
	g++ -c -o Test1.o Test1.cpp 

Event.o : Classes/Event.cpp Classes/Event.h
	g++ -c -o Event.o Classes/Event.cpp

clean:
	rm -f $(OBJECTS) $(PROGRAMS)