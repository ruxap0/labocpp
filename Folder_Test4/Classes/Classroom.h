#pragma once
#include "Schedulable.h"
using namespace std;
#include <iostream>

#ifndef CLASSROOM_H
#define CLASSROOM_H

class Classroom : public Schedulable
{
    friend ostream& operator<<(ostream& out, const Classroom& c);

    private :
        string name;
        int seatingCapacity;
    public :
        Classroom();
        Classroom(int id, string name, int seats);
        Classroom(const Classroom &cr);
        ~Classroom();

        string getName() const;
        void setName(const string name);
        int getSeatingCapacity() const;
        void setSeatingCapacity(const int seats);

        string toString() const override;
        string tuple() const override;

        Classroom& operator=(const Classroom &c2);
};

#endif