#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  auto it = first;
  int rang = 0;
  while(it != last){
    it++;
    rang++;
  }
  // std::cout << rang <<std::endl;
  T * arr = new T[rang]();
  int idx = 0;
  auto itend = last;
  itend--;
  for(int i = 0 ; i < rang ; i++){
    // std::cout << *itend << std::endl;
    arr[idx++] = *itend;
    itend--;
  }
  mData = arr;
  mCap = rang;
  mSize = rang;
}

#endif
