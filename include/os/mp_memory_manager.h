#ifndef mp_MenMan_h
#define mp_MenMan_h

#include "mp_thread.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class MP_MemoryManager{
  public:
    void* allocate(int numbytes, MP_Thread *mp_thread);
    void deallocate(MP_Thread *mp_thread);
    void deallocate(MP_Thread *mp_thread, void *mem);

  private:
    std::map <string, list<void *>> m_memory_map;
};

#endif

