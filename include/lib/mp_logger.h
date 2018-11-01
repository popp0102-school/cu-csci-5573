#ifndef MP_LOGGER_H
#define MP_LOGGER_H
#include "mp_thread.h"
#include <iostream>
#include <fstream>

class MP_Logger	//template
{
	private:
		MP_Thread *mp_thread;
		string fileName;
	public:
		MP_Logger();
		MP_Logger(MP_Thread *mp_thread, string fileName);
		~MP_Logger();
		template<class T>
		void log(T mp_obj);//wrote into template
};

#endif