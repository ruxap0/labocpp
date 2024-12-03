#include "Event.h"
#include "TimingException.h"
#include <string.h>
#include <iostream>

using namespace std;

namespace planning
{
	//*********************************************************************************//
	//Constructeurs et destructeurs
	//*********************************************************************************//
	Event::Event() // :: -> montre que Event() appartient à la classe Event
	{
		#ifdef DEBUG
			cout << "Constructeur par défaut" << endl;
		#endif
		code = 0;
		//title = nullptr;
		title = new char[128];
		strcpy(title,"Evenement sans titre");
		timing = nullptr;
		currentCode ++;
	};

	Event::Event(int code, const char* title)
	{
		this->code = code;
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		timing = nullptr;
	}

	Event::Event(Event &temp)
	{
		#ifdef DEBUG
			cout << "Constructeur de copie" << endl;
		#endif

		this->code = temp.code;
		this->title = new char[strlen(temp.title) + 1];
		strcpy(this->title, temp.title);
		this->timing = temp.timing;
	};

	Event::~Event()
	{	
		#ifdef DEBUG
			cout << "Destructeur" << endl;
		#endif
		delete[] this->title;
		delete this->timing;
		currentCode--;
	}

	//*********************************************************************************//
	//Méthodes publiques générales
	//*********************************************************************************//

	int Event::currentCode = 1;


	void Event::display() const{
		cout << "code : " << code << " intitulé : " <<title << endl;
		if(timing != nullptr)
			timing->display();
	}

	void Event::setCode(int code){
		this->code = code;
	}

	void Event::setTitle(const char* title){
		strcpy(this->title, title);
	}

	void Event::setTiming(const Timing& timing)
	{
		this->timing = new Timing;
		this->timing->setDay(timing.getDay());
		this->timing->setStart(timing.getStart());
		this->timing->setDuration(timing.getDuration());
	}

	int Event::getCode() const
	{
		return code; 
	}

	const char* Event::getTitle() const
	{
		return title; 
	}

	Timing Event::getTiming() const
	{
		if(timing == nullptr)
			throw(TimingException("No Timing Available", TimingException::NO_TIMING));

		cout << timing->getDay() << timing->getStart() << timing->getDuration() << endl;

		return (*timing);		
	}

	//*********************************************************************************//
	//Méthodes amies
	//*********************************************************************************//
	ostream& operator<<(ostream& out, const Event& e)
	{
		out << "<Event>" << endl;
		out << "<code>" << endl;
		out << e.code << endl;
		out << "</code>" << endl;
		out << "<title>" << endl;
		out << e.title << endl;
		out << "</title>" << endl;
		
		if(e.timing != nullptr)
		{
			out << "<timing>" << endl;
			out << *e.timing;
			out << "</timing>" << endl;
		}

		out << "</Event>" << endl;

		return out;
	}

	istream& operator>>(istream& in, Event& e)
	{
		string eventCode, tag, eventTitle;
		Timing t;

		getline(in, tag);
		getline(in, tag);
		getline(in, eventCode);
		getline(in, tag);
		getline(in, tag);
		getline(in, eventTitle);
		getline(in, tag);
		getline(in, tag);
		if(tag == "<timing>")
		{
			in >> t;
			e.timing = new Timing;
			e.timing->setDay(t.getDay());
			e.timing->setStart(t.getStart());
			e.timing->setDuration(t.getDuration());
			getline(in, tag);
		}

		getline(in, tag);

		e.code = stoi(eventCode);
		strcpy(e.title, eventTitle.c_str());

		return in;
	}
}