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

    Timing::Timing(string day, Time start, Time duration)
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
    /******************************************/

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
}