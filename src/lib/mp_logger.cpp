#include"mp_logger.h"

MP_Logger::MP_Logger(){
	
}
MP_Logger::~MP_Logger(){

}

MP_Logger::MP_Logger(MP_Thread *mp_thread, std::string fileName){
	this->mp_thread = mp_thread;
	this->fileName = fileName;
}
