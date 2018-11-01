#include"mp_logger.h"

MP_Logger::MP_Logger(){
	
}
MP_Logger::~MP_Logger(){

}

MP_Logger::MP_Logger(MP_Thread *mp_thread, string fileName){
	this.mp_thread = mp_thread;
	this.fileName = fileName;
}

template<class T>
void MP_Logger<T>::log(T mp_obj){
	ofstream logFile;
	logFile.open(fileName);
	logFile << mp_obj;
	logFile.close();
}