#include "Event.h"
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
		if(timing != nullptr)
			return (*timing);
		
		__builtin_unreachable(); // dire au compilo que ça n'arrivera jamais là
	}
}