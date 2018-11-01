#ifndef MP_LOGGER_H
#define MP_LOGGER_H
#include "mp_thread.h"
#include <iostream>
#include <fstream>
#include <string>

class MP_Logger	//template
{
	private:
		MP_Thread *mp_thread;
		std::string fileName;
	public:
		MP_Logger();
		MP_Logger(MP_Thread *mp_thread, std::string fileName);
		~MP_Logger();
		template<class T>
		void log(T mp_obj);//wrote into template
};

template<class T>
void MP_Logger::log(T mp_obj)
{
        std::ofstream logFile;
        logFile.open(fileName, std::ios_base::app);
        logFile << mp_obj;
        logFile.close();

}

#endif
