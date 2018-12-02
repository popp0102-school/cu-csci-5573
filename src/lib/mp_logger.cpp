#include"mp_logger.h"

MP_Logger::MP_Logger(string fileName) {
  this->fileName = fileName;
}

ifstream MP_Logger::ReadFile() {
  ifstream infile(fileName);
  return infile;
}

