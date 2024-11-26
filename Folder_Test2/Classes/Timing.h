#pragma once
#include <string>
#include "Time.h"
using namespace std;

namespace planning
{
    class Timing
    {
        private :
            string day;
            Time start;
            Time duration; 
            
        public :
            const static string MONDAY;
            const static string TUESDAY;
            const static string WEDNESDAY;
            const static string THURSDAY;
            const static string FRIDAY;
            const static string SATURDAY;
            const static string SUNDAY;

            Timing();
            Timing(string day, Time start, Time duration);
            Timing(Timing &temp);
            ~Timing();

            string getDay() const;
            Time getStart() const;
            Time getDuration() const;
            void setDay(string day);
            void setStart(const Time &start);
            void setDuration(const Time &duration);

            void display() const;
    };
}
