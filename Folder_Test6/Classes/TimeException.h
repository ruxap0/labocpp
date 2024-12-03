#include "Exception.h"

#ifndef H_TIMEEXCEPTION
#define H_TIMEEXCEPTION

namespace planning
{
    class TimeException : public Exception
    {
        private :
            int code; //Pour le code d'erreur
        
        public :
            TimeException();
            TimeException(const string msg, const int code);
            TimeException(const TimeException &te);
            ~TimeException();

            int getCode() const;

            const static int INVALID_HOUR;
            const static int INVALID_MINUTE;
            const static int OVERFLOW;
    };
}

#endif