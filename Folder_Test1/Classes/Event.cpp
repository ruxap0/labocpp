#include "Event.h"
#include <string.h>
#include <iostream>

using namespace std;


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
	title = new char[30];
	strcpy(title,"Evenement sans titre");
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
};

Event::~Event()
{	
	#ifdef DEBUG
		cout << "Destructeur" << endl;
	#endif
	delete[] this->title;
}

//*********************************************************************************//
//Méthodes publiques générales
//*********************************************************************************//

void Event::display() const{
	cout << "code : " << code << " intitulé : " <<title << endl;
	//Si on utilisait nullptr, faudrait mettre une condition pour ne pas afficher qqch qui n'existe pas
}

void Event::setCode(int code){
	this->code = code;
}

void Event::setTitle(const char* title){
	strcpy(this->title, title);
}

int Event::getCode() const
{
	return code; 
}

const char* Event::getTitle() const
{
	return title; 
}
