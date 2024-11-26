#makefile du test 5

.SILENT:

OBJECTS = Test5.o Event.o Time.o Timing.o Exception.o TimeException.o TimingException.o
CLASSPATH = ./Classes/
PROGRAMS = Test5

all : $(PROGRAMS)


Test5 : $(OBJECTS)
	echo Compilation de Test5
	g++ -o Test5 $(OBJECTS) -fsanitize=undefined -fsanitize=address -g

Test5.o : Test5.cpp
	echo Compilation de Test5.o
	g++ -c -o Test5.o Test5.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Event.o : $(CLASSPATH)Event.cpp $(CLASSPATH)Event.h
	echo Compilation de Event.o
	g++ -c -o Event.o $(CLASSPATH)Event.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Time.o : $(CLASSPATH)Time.cpp $(CLASSPATH)Time.h
	echo Compilation de Time.o
	g++ -c -o Time.o $(CLASSPATH)Time.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Timing.o : $(CLASSPATH)Timing.cpp $(CLASSPATH)Timing.h
	echo Compilation de Timing.o
	g++ -c -o Timing.o $(CLASSPATH)Timing.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

TimeException.o : $(CLASSPATH)TimeException.cpp $(CLASSPATH)TimeException.h
	echo Compilation de TimeException.o
	g++ -c -o TimeException.o $(CLASSPATH)TimeException.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

TimingException.o : $(CLASSPATH)TimingException.cpp $(CLASSPATH)TimingException.h
	echo Compilation de TimingException.o
	g++ -c -o TimingException.o $(CLASSPATH)TimingException.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG



clean :
	rm -f $(PROGRAMS) $(OBJECTS)