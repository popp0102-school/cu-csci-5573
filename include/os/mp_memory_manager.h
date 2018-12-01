#ifndef mp_MenMan_h
#define mp_MenMan_h

#include "mp_thread.h"
#include <map>
#include <string>

class MP_MemoryManager{
  public:
    void* allocate(int numbytes, MP_Thread *mp_thread);
    void deallocate(MP_Thread *mp_thread);

  private:
    std::map <std::string, void *> mp_memory_map;
};

#endif

