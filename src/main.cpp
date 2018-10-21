#include "mp_os.h"
#include <iostream>
#include <unistd.h>

void function1() {
  std::cout << "function 1 here\n";
}

void function2() {
  std::cout << "function 2 here\n";
}

void function3() {
  int count = 0;
  while(1) {
    count++;
    if (count % 100000000 == 0 ) {
      std::cout << "function 3 here\n";
    }
  }
}

void function4() {
  int count = 0;
  while(1) {
    count++;
    if (count % 100000000 == 0 ) {
      std::cout << "function 4 here\n";
    }
  }
}

int main() {
  MP_OS *mpos = new MP_OS(MP_Scheduler::FCFS);

  mpos->thread_create(function3);
  mpos->thread_create(function4);

  mpos->run();

  return 0;
}

/*
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void function3(const boost::system::error_code& /) {
  std::cout << "fuck yeah!\n";
}

  boost::asio::io_service io;
  boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
  std::cout << "before!\n";
  t.async_wait(&function3);
  while(1) {
    io.poll();
  }
  std::cout << "after!\n";

*/

