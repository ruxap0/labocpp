#pragma once
#include "Schedulable.h"
using namespace std;
#include <iostream>

#ifndef GROUP_H
#define GROUP_H


class Group : public Schedulable
{
    friend ostream& operator<<(ostream& out, const Group& g);

    private :
        string name;
    public :
        Group();
        Group(int id, string name);
        Group(const Group &grp);
        ~Group();

        string getName() const;
        void setName(const string name);

        string toString() const override;
        string tuple() const override;
        Group& operator=(const Group &group);
};

#endif