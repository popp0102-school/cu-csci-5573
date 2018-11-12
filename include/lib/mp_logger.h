#ifndef MP_LOGGER_H
#define MP_LOGGER_H
#include "mp_thread.h"
#include <iostream>
#include <fstream>
#include <string>

class MP_Logger	//template
{
	private:
		std::string fileName;
	public:
		MP_Logger(std::string fileName);

		template<class T>
		void log(T mp_obj);//wrote into template

		std::ifstream ReadFile();
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
