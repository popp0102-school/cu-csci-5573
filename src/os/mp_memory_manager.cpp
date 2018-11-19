#include "mp_memory_manager.h"

#include <malloc.h>
#include <ucontext.h>

using namespace std;

void* MP_MemoryManager::allocate(int numbytes, MP_Thread *mp_thread){
  void *mem = malloc(numbytes);
  mp_memory_map.insert(std::pair<std::string, void*> (mp_thread->getLabel(), mem));
  return mem;
}

void MP_MemoryManager::deallocate(MP_Thread *mp_thread){
  free(mp_memory_map[mp_thread->getLabel()]);
}

