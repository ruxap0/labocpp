#makefile du test 5

.SILENT:

OBJECTS = Test6.o Event.o Time.o Timing.o Exception.o TimeException.o TimingException.o Schedulable.o Group.o Professor.o Classroom.o
CLASSPATH = ./Classes/
PROGRAMS = Test6

all : $(PROGRAMS)


Test6 : $(OBJECTS)
	echo Compilation de Test6
	g++ -o Test6 $(OBJECTS) -fsanitize=undefined -fsanitize=address -g

Test6.o : Test6.cpp
	echo Compilation de Test6.o
	g++ -c -o Test6.o Test6.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Event.o : $(CLASSPATH)Event.cpp $(CLASSPATH)Event.h
	echo Compilation de Event.o
	g++ -c -o Event.o $(CLASSPATH)Event.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Time.o : $(CLASSPATH)Time.cpp $(CLASSPATH)Time.h
	echo Compilation de Time.o
	g++ -c -o Time.o $(CLASSPATH)Time.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Timing.o : $(CLASSPATH)Timing.cpp $(CLASSPATH)Timing.h
	echo Compilation de Timing.o
	g++ -c -o Timing.o $(CLASSPATH)Timing.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Exception.o : $(CLASSPATH)Exception.cpp $(CLASSPATH)Exception.h
	echo Compilation de Exception.o
	g++ -c -o Exception.o $(CLASSPATH)Exception.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

TimeException.o : $(CLASSPATH)TimeException.cpp $(CLASSPATH)TimeException.h
	echo Compilation de TimeException.o
	g++ -c -o TimeException.o $(CLASSPATH)TimeException.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

TimingException.o : $(CLASSPATH)TimingException.cpp $(CLASSPATH)TimingException.h
	echo Compilation de TimingException.o
	g++ -c -o TimingException.o $(CLASSPATH)TimingException.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Schedulable.o : $(CLASSPATH)Schedulable.cpp $(CLASSPATH)Schedulable.h
	echo Compilation de Schedulable.o
	g++ -c -o Schedulable.o $(CLASSPATH)Schedulable.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Group.o : $(CLASSPATH)Group.cpp $(CLASSPATH)Group.h Schedulable.o
	echo Compilation de Group.o
	g++ -c -o Group.o $(CLASSPATH)Group.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Professor.o : $(CLASSPATH)Professor.cpp $(CLASSPATH)Professor.h Schedulable.o
	echo Compilation de Professor.o
	g++ -c -o Professor.o $(CLASSPATH)Professor.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

Classroom.o : $(CLASSPATH)Classroom.cpp $(CLASSPATH)Classroom.h Schedulable.o
	echo Compilation de Classroom.o
	g++ -c -o Classroom.o $(CLASSPATH)Classroom.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG


clean :
	rm -f $(PROGRAMS) $(OBJECTS)
	rm -f *.xml