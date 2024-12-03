#pragma once
#include <string>
#include "Time.h"
using namespace std;

#ifndef TIMING_H
#define TIMING_H

namespace planning
{
    class Timing
    {
        friend ostream& operator<<(ostream& out, const Timing& t);
        friend istream& operator>>(istream& in, Timing& t);

        private :
            string day;
            Time start;
            Time duration; 

            int compTiming(const Timing &t2) const;
            
        public :
            //variables membres
            const static string MONDAY;
            const static string TUESDAY;
            const static string WEDNESDAY;
            const static string THURSDAY;
            const static string FRIDAY;
            const static string SATURDAY;
            const static string SUNDAY;

            //constructeurs et destructeurs
            Timing();
            Timing(string day, const Time &start, const Time &duration);
            Timing(Timing &temp);
            ~Timing();

            //getters et setters
            string getDay() const;
            Time getStart() const;
            Time getDuration() const;
            void setDay(string day);
            void setStart(const Time &start);
            void setDuration(const Time &duration);

            //display
            void display() const;

            //surchage des opérateurs
            int operator<(const Timing &t2) const;
            int operator>(const Timing &t2) const;
            int operator==(const Timing &t2) const;

            int jour() const;
    };
}

#endif