#include "Timing.h"
#include <iostream>


namespace planning
{
    /******************************************/
    /****** Constructeurs et Destructeur ******/
    /******************************************/

    Timing::Timing()
    {
        day = "No day yet";
        start = Time(0, 0);
        duration = Time(0, 0);
    }

    Timing::Timing(string day, const Time &start, const Time &duration)
    {
        this->day = day;
        this->start.setHour(start.getHour());
        this->start.setMinute(start.getMinute());
        this->duration.setHour(duration.getHour());
        this->duration.setMinute(duration.getMinute());
    }

    Timing::Timing(Timing &temp)
    {
        this->day = temp.day;
        this->start.setHour(temp.start.getHour());
        this->start.setMinute(temp.start.getMinute());
        this->duration.setHour(temp.duration.getHour());
        this->duration.setMinute(temp.duration.getMinute());
    }

    Timing::~Timing(){}

    /******************************************/
    /****** Méthodes publiques générales ******/
    /****S**************************************/

    const string Timing::MONDAY = "Lundi";
    const string Timing::TUESDAY = "Mardi";
    const string Timing::WEDNESDAY = "Mercredi";
    const string Timing::THURSDAY = "Jeudi";
    const string Timing::FRIDAY = "Vendredi";
    const string Timing::SATURDAY = "Samedi";
    const string Timing::SUNDAY = "Dimanche";

    string Timing::getDay() const
    {
        return day;
    }

    Time Timing::getStart() const
    {
        return start;
    }

    Time Timing::getDuration() const
    {
        return duration;
    }

    void Timing::setDay(string day)
    {
        if(day == "Lundi" || day == "Mardi" || day == "Mercredi" || day == "Jeudi" || day == "Vendredi" || day == "Samedi" || day == "Dimanche")
            this->day = day;
        else
            fprintf(stderr, "Jour encodé non conforme...\n");
    }

    void Timing::setStart(const Time &start)
    {
        this->start.setHour(start.getHour());
        this->start.setMinute(start.getMinute());
    }

    void Timing::setDuration(const Time &duration)
    {
        this->duration.setHour(duration.getHour());
        this->duration.setMinute(duration.getMinute());
    }

    void Timing::display() const
    {
        cout << day << " à ";
        start.display();
        cout << " et a une durée de ";
        duration.display();
    }

    /******************************************/
    /******** Surcharge des Operateurs ********/
    /******************************************/
    int Timing::jour() const
    {
        if (day == MONDAY) return 1;
        if (day == TUESDAY) return 2;
        if (day == WEDNESDAY) return 3;
        if (day == THURSDAY) return 4;
        if (day == FRIDAY) return 5;
        if (day == SATURDAY) return 6;
        if (day == SUNDAY) return 7;
           return -1;
    }

    int Timing::compTiming(const Timing &t2) const 
    {
        if (jour() < t2.jour()) return -1;
        if (jour() > t2.jour()) return 1;
        if (jour() == t2.jour())
        {
            if(start < t2.start)return -1;
            if(start > t2.start)return 1;
            if(start == t2.start)
            {
                if(duration < t2.duration)return -1;
                if(duration > t2.duration)return 1;
            }
        }
        return 0;
    }
    int Timing::operator>(const Timing &t2) const
    {
        return compTiming(t2) == 1;
    }

    int Timing::operator<(const Timing &t2) const
    {
        return compTiming(t2) == -1;
    }

    int Timing::operator==(const Timing &t2) const
    {
        return compTiming(t2) == 0;
    }

}