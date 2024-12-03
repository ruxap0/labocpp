#pragma once
#include <iostream>

using namespace std;

#ifndef TIME_H
#define TIME_H

namespace planning
{
    class Time 
    {
        friend Time operator+(int min, Time &time);
        friend Time operator-(int min, Time &time);

        friend ostream& operator<<(ostream& out, const Time& time);
        friend istream& operator>>(istream& in, Time& time);

        private:
            int hour;
            int minute;
            
        public:
            //constructeurs & destructeurs
            Time();
            Time(int ho, int min);
            Time(int min);
            Time(const Time &temp);
            ~Time(); // useless car pas de variables allouées dynamiquement
            
            //getters & setters
            int getHour() const;
            int getMinute() const;
            void setHour(int hour);
            void setMinute(int minute);

            //display
            void display() const;

            //surcharge des opérateurs
            Time& operator=(const Time &h2);
            Time operator+(int min);
            Time operator+(const Time &h2);

            Time operator-(int);
            Time operator-(const Time &h2);

            bool operator<(const Time &h2) const;
            bool operator>(const Time &h2) const;
            bool operator==(const Time &h2) const;

            Time operator++();
            Time operator++(int);
            Time operator--();
            Time operator--(int);
    };
}

#endif