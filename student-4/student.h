#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  // Your code here
  // Return something
  for(int i = 0 ; i < mSize ; i++){
    if(i == 0){
      ;
    }else{
      if(mLess(mData[(i-1)/2],mData[i])){
        return false;
      }else{
        ;
      }
    }
  }
  return true;
}

#endif