#include "Event.h"
#include <string.h>
#include <iostream>

using namespace std;


//*********************************************************************************//
//Constructeurs et destructeurs
//*********************************************************************************//

Event::Event() // :: -> montre que Event() appartient à la classe Event
{
	code = 0;
	//title = nullptr;
	title = new char[30];
	strcpy(title,"Evenement sans titre");
};

Event::Event(int code, const char* title) // :: -> montre que Event() appartient à la classe Event
{
	this->code = code;
	//title = nullptr;
	this->title = new char[30];
	strcpy(this->title, title);
};

Event::~Event()
{
	delete this->title;
}

//*********************************************************************************//
//Méthodes publiques générales
//*********************************************************************************//

void Event::display(){
	cout << "code : " << code << " intitulé : " <<title << endl;
	//Si on utilisait nullptr, faudrait mettre une condition pour ne pas afficher qqch qui n'existe pas
}

void Event::setCode(int code){
	this->code = code;
}

void Event::setTitle(const char* title){
	strcpy(this->title, title);
}

int Event::getCode()
{
	return code; 
}

char* Event::getTitle(){
	return title; 
}
