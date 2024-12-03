#include "Group.h"
#include <iostream>
using namespace std;

Group::Group():Schedulable()
{
    name = "----";
}

Group::Group(int id, string name):Schedulable(id)
{
    this->name = name;
}

Group::Group(const Group &grp):Schedulable(grp)
{
    this->name = grp.name;
}

Group::~Group()
{
    cout << "Destructeur de Group" << endl;
}

string Group::getName() const
{
    return name;
}

void Group::setName(const string name)
{
    this->name = name;
}

string Group::toString() const
{
    return "<< " + name + " >>";
}

string Group::tuple() const
{
    return "<< " + to_string(id) + ';' + name + " >>";
}

ostream& operator<<(ostream& out, const Group& g)
{
    return out << g.toString();
}

Group& Group::operator=(const Group& g2)
{
    name = g2.name;

    return (*this);
}
