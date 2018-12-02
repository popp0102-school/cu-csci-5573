#ifndef MP_LOGGER_H
#define MP_LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MP_Logger  //template
{
  private:
    string fileName;
  public:
    MP_Logger(string fileName);

    template<class T>
    void log(T mp_obj);//wrote into template

    ifstream ReadFile();
};

template<class T>
void MP_Logger::log(T mp_obj)
{
  ofstream logFile;
  logFile.open(fileName, ios_base::app);
  logFile << mp_obj;
  logFile.close();
}

#endif

