#include "Time.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <TimeException.h>
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

    Time::Time(int ho, int min) throw(TimeException)
    {
        hour = ho;
        minute = min;
    }

    Time::Time(int duration)
    {
        minute = duration % 60;
        hour = duration / 60;
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

    /*************************************************/
    /*********** Surchage des opérateurs *************/
    /*************************************************/

    Time& Time::operator=(const Time &h2)
    {
        hour = h2.getHour();
        minute = h2.getMinute();

        return (*this);
    }

    Time Time::operator+(int min)
    {
        Time temp(*this);

        if(min < 0)
            return temp;

        temp.minute += min;

        if(temp.minute >= 60)
        {
            temp.hour += (temp.minute / 60);
            temp.minute = temp.minute % 60;

            if(temp.hour >= 24)
                temp.hour = temp.hour % 24;
        }

        return temp;
    }
    
    Time Time::operator+(const Time &t2)
    {
        Time temp(*this);

        temp.minute += t2.getMinute();
        if(temp.minute >= 60)
        {
            temp.hour ++; //ça sera forcément +1 car le reste est traité avant par les constructeurs
            temp.minute = temp.minute % 60;
        }

        temp.hour += t2.getHour();
        if(temp.hour >= 24)
            temp.hour = temp.hour % 24;

        return temp;
    }

    Time Time::operator-(int min) // à vérifier
    {
        Time temp(*this);

        if(min < 0)
            return temp;

        temp.minute -= min;

        while(temp.minute < 0)
        {
            temp.hour --;
            temp.minute += 60;
        }

        if(temp.hour < 0)
            temp.hour = 24 + temp.hour;

        return temp;
    }

    Time Time::operator-(const Time &t2)
    {
        Time temp(*this);
        
        temp.hour -= t2.getHour();

        if (temp.hour < 0)
            temp.hour = 24 + temp.hour;  

        temp = temp - t2.getMinute();

        return temp;
    }

    bool Time::operator<(const Time &h2) const
    {
        if(h2.getHour() > this->hour)
            return true;
        else if (h2.getHour() == this->hour)
            if (h2.getMinute() > this->minute)
                return true;

        return false;
    }
    
    bool Time::operator>(const Time &h2) const
    {
        if(this->hour > h2.hour)
            return true;
        else if (this->hour == h2.hour)
            if (this->minute > h2.minute)
                return true;

        return false;
    }
    
    bool Time::operator==(const Time &h2) const
    {
        if(this->hour == h2.getHour() and this->minute == this->minute)
            return true;
        else
            return false;
    }

    /*************************************************/
    /**************** Méthodes Amies *****************/
    /*************************************************/

    Time operator+(int min, Time &time)
    {
        return time + min;
    }

    Time operator-(int min, Time &time)
    {
        int difference = min - (time.hour * 60 + time.minute);
        return Time(difference);
    }

    ostream& operator<<(ostream& out, const Time& time)
    {
        out << std::setfill('0') << std::setw(2) << time.hour << "h" << std::setfill('0') << std::setw(2) << time.getMinute();

        return out;
    }
    
    istream& operator>>(istream& in, Time& time)
    {
        char separator;
        bool check = false;

        do {
            cout << "Time you want : ";
            in >> time.hour >> separator >> time.minute;
            cout << endl;

            if (separator != 'h' && separator != ':' || time.hour < 0 || time.hour > 23 || time.minute < 0 || time.minute > 59)
                cout << "Error in Time encoding... Try again" << endl;
            else
                check = true;

        }while(!check);

        return in;
    }

    Time Time::operator++()
    {
        (*this) = (*this) + 30;

        return (*this);
    }

    Time Time::operator++(int)
    {
        Time temp(*this);

        (*this) = (*this) + 30;

        return temp;
    }

    Time Time::operator--()
    {
        (*this) = (*this) - 30;

        return (*this);
    }
    
    Time Time::operator--(int)
    {
        Time temp(*this);

        (*this) = (*this) - 30;

        return temp;
    }
}


