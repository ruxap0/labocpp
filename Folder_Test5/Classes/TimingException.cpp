using namespace std;
#include "TimingException.h"
#include "Timing.h"
#include <iostream>

namespace planning
{
    const int TimingException::NO_TIMING = 1;
    const int TimingException::INVALID_DAY = 2;
    
    TimingException::TimingException():Exception()
    {
        code = 0;
    }

    TimingException::TimingException(const string message, const int code):Exception(message)
    {
        this->code = code;
    }

    TimingException::TimingException(const TimingException &te):Exception(te)
    {
        code = te.code;
    }

    TimingException::~TimingException()
    {
        cout << "Destructeur de TimingException" << endl;
    }

    int TimingException::getCode() const
    {
        return code;
    }
}