//#pragma once

class Event
{
	private:
		int code;
		char* title;

	public:
		Event();
		Event(int code, const char* title);
		~Event();
		void display();
		void setCode(int code);
		void setTitle(const char* title);
		int getCode();
		char* getTitle();
};