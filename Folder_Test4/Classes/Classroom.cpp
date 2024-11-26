#include "Classroom.h"
#include <iostream>
using namespace std;

Classroom::Classroom():Schedulable()
{
    name = "----";
    seatingCapacity = 0;
}

Classroom::Classroom(int id, string name, int seats):Schedulable(id)
{
    this->name = name;
    seatingCapacity = seats;
}

Classroom::Classroom(const Classroom &cr):Schedulable(cr)
{
    name = cr.name;
    seatingCapacity = cr.seatingCapacity;
}

Classroom::~Classroom()
{
    cout << "Destructeur de Classroom" << endl;
}

string Classroom::getName() const
{
    return name;
}

void Classroom::setName(const string name)
{
    this->name = name;
}

int Classroom::getSeatingCapacity() const
{
    return seatingCapacity;
}

void Classroom::setSeatingCapacity(const int seats)
{
    seatingCapacity = seats;
}

string Classroom::toString() const
{
    return "<< " + name + '(' + to_string(seatingCapacity) + ')' + " >>";
}

string Classroom::tuple() const
{
    return "<< " + to_string(id) + ';' + name + '(' + to_string(seatingCapacity) + ')' + " >>";
}

ostream& operator<<(ostream& out, const Classroom& c2)
{
    return out <<c2.toString();
}

Classroom& Classroom::operator=(const Classroom& c2)
{
    name = c2.name;
    seatingCapacity = c2.seatingCapacity;

    return (*this);
}