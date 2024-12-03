#include "Timing.h"
#include "TimingException.h"
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

        if(jour() == -1)
            throw(TimingException("No Valid Day", TimingException::INVALID_DAY));
    }

    Timing::Timing(Timing &temp)
    {
        this->day = temp.day;
        this->start = temp.start; // ... Parce que avant ce n'était en pas référence :/
        this->start.setMinute(temp.start.getMinute());
        this->duration.setHour(temp.duration.getHour());
        this->duration.setMinute(temp.duration.getMinute());

        if(jour() == -1)
            throw(TimingException("No Valid Day", TimingException::INVALID_DAY));
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
        this->day = day;

        if(jour() == -1)
            throw(TimingException("No Valid Day", TimingException::INVALID_DAY));   
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

    ostream& operator<<(ostream& out, const Timing& t)
    {
        out << "<Timing>" << endl;
        out << "<day>" << endl;
        out << t.day << endl;
        out << "</day>" << endl;
        out << "<start>" << endl;
        out << t.start;
        out << "</start>" << endl;
        out << "<duration>" << endl;
        out << t.duration;
        out << "</duration>" << endl;
        out << "</Timing>" << endl;

        return out;
    }

    istream& operator>>(istream& in, Timing& t)
    {
        string timingDay, tag;

        getline(in, tag);
        getline(in, tag);
        getline(in, timingDay);
        getline(in, tag);
        getline(in, tag);
        cout << endl << timingDay << endl;
        in >> t.start;
        getline(in, tag);
        getline(in, tag);
        in >> t.duration;
        getline(in, tag);
        getline(in, tag);

        t.day = timingDay;

        return in;
    }

}