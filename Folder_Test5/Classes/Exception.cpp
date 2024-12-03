#include "Exception.h"
using namespace planning;
#include <iostream>

Exception::Exception()
{
    message = "------------";
}

Exception::Exception(const string msg)
{
    message = msg;
}

Exception::Exception(const Exception &exc)
{
    message = exc.message;
}

Exception::~Exception()
{
    cout << "Destructeur d'Exception" << endl;
}

string Exception::getMessage() const
{
    return message;
}