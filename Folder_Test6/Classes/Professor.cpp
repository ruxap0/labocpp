#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor():Schedulable()
{
    firstName = lastName = "----";
}

Professor::Professor(int id, string fN, string lN):Schedulable(id)
{
    firstName = fN;
    lastName = lN;
}

Professor::Professor(const Professor& prof):Schedulable(prof)
{
    firstName = prof.firstName;
    lastName = prof.lastName;
}

Professor::~Professor()
{
        cout << "Destructeur de Professor" << endl;

}

string Professor::getFirstName() const
{
    return firstName;
}

void Professor::setFirstName(const string fN)
{
    firstName = fN;
}

string Professor::getLastName() const
{
    return lastName;
}

void Professor::setLastName(const string lN)
{
    lastName = lN;
}

string Professor::toString() const
{
    return "<< " + lastName + " " + firstName + " >>";
}

string Professor::tuple() const
{
    return "<< " + to_string(id) + ';' + lastName + ';' + firstName + " >>";
}

ostream& operator<<(ostream& out, const Professor& p)
{
    return out << p.toString();
}

Professor& Professor::operator=(const Professor& p2)
{
    firstName = p2.firstName;
    lastName = p2.lastName;

    return (*this);
}