# Makefile du Test2

.SILENT:

OBJECTS = Test2.o Time.o Event.o Timing.o
CLASSPATH = Classes/

PROGRAMS = Test2

all: $(PROGRAMS)

Test2 : Test2.o Event.o Time.o Timing.o
	g++ -o Test2 Event.o Test2.o Time.o Timing.o -fsanitize=undefined -fsanitize=address -g

Test1.o : Test2.cpp
	echo Compilation du Test2
	g++ -c -o Test2.o Test2.cpp -D DEBUG -fsanitize=undefined -fsanitize=address -g

Event.o : $(CLASSPATH)Event.cpp $(CLASSPATH)Event.h
	g++ -c -o Event.o $(CLASSPATH)Event.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Time.o : $(CLASSPATH)Time.cpp $(CLASSPATH)Time.h
	g++ -c -o Time.o $(CLASSPATH)Time.cpp -fsanitize=undefined -fsanitize=address -g

Timing.o : $(CLASSPATH)Timing.cpp $(CLASSPATH)Timing.h
	g++ -c -o Timing.o $(CLASSPATH)Timing.cpp -fsanitize=undefined -fsanitize=address -g


clean:
	rm -f $(OBJECTS) $(PROGRAMS)