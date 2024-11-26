#pragma once

namespace planning
{
    class Time 
    {
        private:
            int hour;
            int minute;
            
        public:
            Time();
            Time(int ho, int min);
            Time(int min);
            Time(const Time &temp);
            ~Time(); // useless car pas de variables allouées dynamiquement
            int getHour() const;
            int getMinute() const;
            void setHour(int hour);
            void setMinute(int minute);
            void display() const;
    };
}