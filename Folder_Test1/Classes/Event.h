//#pragma once

#ifndef EVENT_H //si tu ne connais pas cette macro...
#define EVENT_H //crée là 

class Event
{
	private:
		int code;
		char* title;

	public:
		Event();
		Event(Event &temp);
		Event(int code, const char* title);
		~Event();
		void display() const;
		void setCode(int code);
		void setTitle(const char* title);
		int getCode() const;
		const char* getTitle() const;
};

#endif