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

ostream& operator<<(ostream& out, const Classroom& c)
{
    out << "<Classroom>" << endl;
    out << "<id>" << endl;
    out << c.id << endl;
    out << "</id>" << endl;
    out << "<name>" << endl;
    out << c.name << endl;
    out << "</name>" << endl;
    out << "<seatingCapacity>" << endl;
    out << c.seatingCapacity << endl;
    out << "</seatingCapacity>" << endl;
    out << "</Classroom>" << endl;

    return out;
}

istream& operator>>(istream& in, Classroom& c2)
{
    string tag, classId, className, classSeats;
    getline(in, tag);
    getline(in, tag);
    getline(in, classId);
    getline(in, tag);
    getline(in, tag);
    getline(in, className);
    getline(in, tag);
    getline(in, tag);
    getline(in, classSeats);
    getline(in, tag);
    getline(in, tag);

    c2.id = stoi(classId);
    c2.name = className;
    c2.seatingCapacity = stoi(classSeats);

    return in;
}

Classroom& Classroom::operator=(const Classroom& c2)
{
    name = c2.name;
    seatingCapacity = c2.seatingCapacity;

    return (*this);
}