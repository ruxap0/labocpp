# Makefile du Test3

.SILENT:

OBJECTS = Test3.o Time.o Event.o Timing.o
CLASSPATH = ./Classes/
PROGRAMS = Test3

all: $(PROGRAMS)

Test3 : Test3.o Event.o Time.o Timing.o
	g++ -o Test3 Event.o Test3.o Time.o Timing.o -fsanitize=undefined -fsanitize=address -g

Test3.o : Test3.cpp
	echo Compilation du Test3
	g++ -c -o Test3.o Test3.cpp -D DEBUG -fsanitize=undefined -fsanitize=address -g

Event.o : $(CLASSPATH)Event.cpp $(CLASSPATH)Event.h
	g++ -c -o Event.o $(CLASSPATH)Event.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Time.o : $(CLASSPATH)Time.cpp $(CLASSPATH)Time.h
	g++ -c -o Time.o $(CLASSPATH)Time.cpp -fsanitize=undefined -fsanitize=address -g

Timing.o : $(CLASSPATH)Timing.cpp $(CLASSPATH)Timing.h
	g++ -c -o Timing.o $(CLASSPATH)Timing.cpp -fsanitize=undefined -fsanitize=address -g


clean:
	rm -f $(OBJECTS) $(PROGRAMS)