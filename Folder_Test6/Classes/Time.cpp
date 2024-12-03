#include "Time.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "TimeException.h"
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
        if(ho > 23 || ho < 0)
            throw(TimeException("Invalid Hour Encoded", TimeException::INVALID_HOUR));
        hour = ho;

        if(min > 59 || min < 0)
            throw(TimeException("Invalid Minute Encoded", TimeException::INVALID_MINUTE));
        minute = min;
    }

    Time::Time(int duration)
    {
        minute = duration % 60;
        hour = duration / 60;
    }

    Time::Time(const Time &temp)
    {
        if(temp.hour > 23 || temp.hour < 0)
            throw(TimeException("Invalid Hour Encoded", TimeException::INVALID_HOUR));
        this->hour = temp.hour;

        if(temp.minute > 59 || temp.minute < 0)
            throw(TimeException("Invalid Minute Encoded", TimeException::INVALID_MINUTE));
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
        if(ho > 23 || ho < 0)
            throw(TimeException("Invalid Hour Encoded", TimeException::INVALID_HOUR));
        hour = ho;
    }

    void Time::setMinute(int min)
    {
        if(min > 59 || min < 0)
            throw(TimeException("Invalid Minute Encoded", TimeException::INVALID_MINUTE));
        minute = min;
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

        while(temp.minute / 60 > 0)
        {
            temp.hour++;
            temp.minute -= 60;
        }

        if(temp.hour > 23)
            throw(TimeException("Hours Overflowed", TimeException::OVERFLOW));

        return temp;
    }
    
    Time Time::operator+(const Time &t2)
    {
        Time temp(*this);

        temp.minute += t2.minute;
        if(temp.minute >= 60)
        {
            temp.hour ++; //ça sera forcément +1 car le reste est traité avant par les constructeurs
            temp.minute = temp.minute % 60;
        }

        temp.hour += t2.hour;

        if(temp.hour > 23)
            throw(TimeException("Hours Overflow", TimeException::OVERFLOW));

        return temp;
    }

    Time Time::operator-(int min)
    {
        Time temp(*this);

        if(min < 0)
            return temp;

        temp.minute -= min;

        while(temp.minute < 0)
        {
            temp.hour--;
            temp.minute += 60;
        }

        if(temp.hour < 0)
            throw(TimeException("Hours Overflowed", TimeException::OVERFLOW));

        return temp;
    }

    Time Time::operator-(const Time &t2)
    {
        Time temp(*this);
        
        temp.minute -= t2.minute;
        if(temp.minute < 0)
        {
            temp.hour--; //techniquement oui
            temp.minute = 60 + temp.minute;
        }

        temp.hour-= t2.hour;

        if(temp.hour < 0)
            throw(TimeException("Hours Overflow", TimeException::OVERFLOW));
        
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
        if(this->hour == h2.getHour() and this->minute == h2.minute)
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
        out << "<Time>" << endl;
        out << "<hour>" << endl;
        out << time.hour << endl;
        out << "</hour>" << endl;
        out << "<minute>" << endl;
        out << time.minute << endl;
        out << "</minute>" << endl;
        out << "</Time>" << endl;

        return out;
    }
    
    istream& operator>>(istream& in, Time& time)
    {
        string timeHour, timeMinute, tag;

        getline(in, tag);
        getline(in, tag);
        getline(in, timeHour);
        getline(in, tag);
        getline(in, tag);
        getline(in, timeMinute);
        getline(in, tag);
        getline(in, tag);

        //cout << timeHour << "-------" << timeMinute << endl;

        time.hour = stoi(timeHour);
        time.minute = stoi(timeMinute);

        return in;
    }

    Time Time::operator++()
    {
        (*this) = (*this) + 30;

        if(this->hour > 23)
            throw(TimeException("Hours Overflowed (0-)", TimeException::OVERFLOW));

        return (*this);
    }

    Time Time::operator++(int)
    {
        Time temp(*this);

        (*this) = (*this) + 30;

        if(this->hour > 23)
            throw(TimeException("Hours Overflowed (23+)", TimeException::OVERFLOW));

        return temp;
    }

    Time Time::operator--()
    {
        (*this) = (*this) - 30;

        if(this->hour < 0)
            throw(TimeException("Hours Overflowed (0-)", TimeException::OVERFLOW));

        return (*this);
    }
    
    Time Time::operator--(int)
    {
        Time temp(*this);

        (*this) = (*this) - 30;

        if(this->hour < 0)
            throw(TimeException("Hours Overflowed (0-)", TimeException::OVERFLOW));

        return temp;
    }
}