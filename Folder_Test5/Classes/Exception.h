#pragma once
using namespace std;
#include <string.h>
#include <iostream>

#ifndef EXCEPTION_H
#define EXCEPTION_H


namespace planning
{
    class Exception
    {
        protected:
            string message;
        public:
            Exception();
            Exception(const string msg);
            Exception(const Exception &exc);
            virtual ~Exception();

            string getMessage() const;
    };
}


#endif