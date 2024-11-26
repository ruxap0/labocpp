# Makefile de l'exercice 4

.SILENT:

OBJECTS = Test4.o Schedulable.o Group.o Professor.o Classroom.o
PROGRAMS = Test4
CLASSPATH = ./Classes/

all : $(PROGRAMS)

Test4 : $(OBJECTS)
	echo Compilation de Test4
	g++ -o Test4 $(OBJECTS) -fsanitize=undefined -fsanitize=address -g

Test4.o : Test4.cpp
	echo Compilation de Test4.o
	g++ -c -o Test4.o Test4.cpp -fsanitize=undefined -fsanitize=address -g -D DEBUG

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