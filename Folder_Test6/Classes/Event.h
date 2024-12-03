#pragma once
#include "Timing.h"

#ifndef EVENT_H //si tu ne connais pas cette macro...
#define EVENT_H //crée là 

namespace planning
{
	class Event
	{
		friend ostream& operator<<(ostream& out, const Event& e);
		friend istream& operator>>(istream& in, Event& e);

		private:
			int code;
			char* title;
			Timing* timing;

		public:
			static int currentCode;
			Event();
			Event(Event &temp);
			Event(int code, const char* title);
			~Event();
			void display() const;
			void setCode(int code);
			void setTitle(const char* title);
			void setTiming(const Timing& timing);
			int getCode() const;
			const char* getTitle() const;
			Timing getTiming() const;
	};
}
#endif