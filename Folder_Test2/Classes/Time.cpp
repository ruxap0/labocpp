#include "Time.h"
#include <iostream>
#include <iomanip>
using namespace std;



namespace planning
{
    /*************************************************/
    /********* Constructeurs et Destructeurs *********/
    /*************************************************/
    Time::Time()
    {
        hour = 0;
        minute = 0;
    }

    Time::Time(int ho, int min)
    {
        hour = ho;
        minute = min;
    }

    Time::Time(int duration)
    {
        hour = duration / 60;
        minute = duration % 60;
    }

    Time::Time(const Time &temp)
    {
        this->hour = temp.hour;
        this->minute = temp.minute;
    }

    Time::~Time(){} // useless car pas de variables allouées dynamiquement

    /*************************************************/
    /********* Méthodes publiques générales **********/
    /*************************************************/


    int Time::getHour() const
    {
        return hour;
    }

    int Time::getMinute() const
    {
        return minute;
    }

    void Time::setHour(int ho)
    {
        if(ho < 24 && ho >= 0)
            hour = ho;
        else
        {
            fprintf(stderr,"Nombre d'heure encodé non conforme...\n");
            hour = 0;
        }
    }

    void Time::setMinute(int min)
    {
        if(min < 60 && min >= 0)
            minute = min;
        else
        {
            fprintf(stderr, "Nombre de minutes encodé non conforme...\n");
        }
    }

    void Time::display() const
    {
        std::cout << std::setfill('0') << std::setw(2) << hour << "h" << std::setfill('0') << std::setw(2) << minute;
    }
}