#include"mp_logger.h"

MP_Logger::MP_Logger(std::string fileName)
{
	this->fileName = fileName;
}

std::ifstream MP_Logger::ReadFile()
{
	std::ifstream infile(fileName);
	return infile;
}
