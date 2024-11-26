#pragma once
using namespace std;
#include <iostream>

#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H

class Schedulable
{
    friend ostream& operator<<(ostream& out, const Schedulable& s);

    protected:
        int id;
    public:
        Schedulable();
        Schedulable(int id);
        Schedulable(const Schedulable &schedulable);
        virtual ~Schedulable();
         
        void setId(const int id);
        int getId() const;
        
        virtual string toString() const = 0;
        virtual string tuple() const = 0;
        Schedulable& operator=(const Schedulable& s2);
};

#endif