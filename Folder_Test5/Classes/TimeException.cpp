#include <iostream>
#include "TimeException.h"
#include "Exception.h"
#include "Time.h"
using namespace std;

namespace planning
{
    TimeException::TimeException():Exception()
    {
        code = 0;
    }

    TimeException::TimeException(const string msg, const int code):Exception(msg)
    {
        this->code = code;
    }

    TimeException::TimeException(const TimeException &te):Exception(te)
    {
        code = te.code;
    }

    TimeException::~TimeException()
    {
        cout << "Destructeur de TimeException" << endl;
    }

    int TimeException::getCode() const
    {
        return code;
    }

    const int TimeException::INVALID_HOUR = 1;
    const int TimeException::INVALID_MINUTE = 2;
    const int TimeException::OVERFLOW = 3;

}