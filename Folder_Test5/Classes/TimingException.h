#include "Exception.h"

#ifndef TIMINGEXCEPTION_H
#define TIMINGEXCEPTION_H

namespace planning
{
    class TimingException : public Exception
    {
        private :
            int code;

        public :
            TimingException();
            TimingException(const string message, const int code);
            TimingException(const TimingException &te);
            ~TimingException();

            int getCode() const;

            const static int NO_TIMING;
            const static int INVALID_DAY;
    };
}

#endif