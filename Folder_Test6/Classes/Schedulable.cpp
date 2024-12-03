#include "Schedulable.h"
#include <iostream>
#include <iomanip>
using namespace std;

Schedulable::Schedulable()
{
    id = 0;
}

Schedulable::Schedulable(int id)
{
    this->id = id;
}

Schedulable::~Schedulable()
{
    cout << "Destructeur de Schedulable" << endl;
}

Schedulable::Schedulable(const Schedulable &schedulable)
{
    this->id = schedulable.id;
}

int Schedulable::getId() const
{
    return id;
}

void Schedulable::setId(const int id)
{
    this->id = id;
}