#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  //your code here
  T * arr = new T[b-a+1]();
  int idx = 0;
  for(int i = b ; i >= a ; i--){
    arr[idx++] = mData[(i+mFront+mCap)%mCap];
  }
  for(int i = 0 ; i < b-a+1 ; i++){
    mData[(a+i+mFront+mCap)%mCap] = arr[i];
  }
}

#endif
