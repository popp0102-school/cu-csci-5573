//
//  Header.h
//  mp_memory
//
//  Created by Natalie Plotkin on 11/8/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//


#include <iterator>
#include <map>
using namespace std;
#ifndef mp_MenMan_h
#define mp_MenMan_h
#include <iostream>
#include <bits/stdc++.h>



class MP_MenMan{
    
public:
 
    MP_MemMan();
    ~MP_MemMan();
    void mp_malloc(int numbytes, MP_Thread *mp_thread);  //call malloc and add to the map
    void deallocate(MP_Thread *mp_thread);
    
    
    
private:

    MP_Thread *mp_thread;
    std::map <std::string, void *> mp_memory_map;
 
};



#endif /* Header_h */
