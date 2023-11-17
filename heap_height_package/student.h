#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
  if(size() == 0){
    return -1;
  }
  int s= size();
  int a = 0;
  while( s != 0){
    s = (s-1)/2;
    a++;
  }
  return a;
}

#endif

