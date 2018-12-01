#include "mp_memory_manager.h"
#include <malloc.h>

void* MP_MemoryManager::allocate(int numbytes, MP_Thread *mp_thread){
  void *mem = malloc(numbytes);
  m_memory_map[mp_thread->getLabel()].push_back(mem);
  return mem;
}

void MP_MemoryManager::deallocate(MP_Thread *mp_thread){
  list<void *> memory_list = m_memory_map[mp_thread->getLabel()];
  list<void *>::iterator it;
  for(it = memory_list.begin(); it != memory_list.end(); it++) {
    free(*it);
  }
}

void MP_MemoryManager::deallocate(MP_Thread *mp_thread, void* mem){
  list<void *> memory_list = m_memory_map[mp_thread->getLabel()];
  list<void *>::iterator it;
  for(it = memory_list.begin(); it != memory_list.end(); it++) {
    if(*it == mem) {
      free(*it);
      break;
    }
  }
}

