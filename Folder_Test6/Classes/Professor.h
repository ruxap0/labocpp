#pragma once
#include "Schedulable.h"
using namespace std;
#include <iostream>

#ifndef PROFESSOR_H
#define PROFESSOR_H

class Professor : public Schedulable
{
    friend ostream& operator<<(ostream& out, const Professor& p);

    private :
        string firstName;
        string lastName;
    public :
        Professor();
        Professor(int id, string fN, string lN);
        Professor(const Professor& prof);
        ~Professor();

        string getFirstName() const;
        string getLastName() const;
        void setFirstName(const string fN);
        void setLastName(const string lN);

        string toString() const override;
        string tuple() const override;
        Professor& operator=(const Professor &p2);
};

#endif