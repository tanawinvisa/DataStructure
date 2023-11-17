#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  int idx = (mFront+mSize-1)%mCap;
  T tmp = mData[idx];
  mData[idx] = mData[(mFront+pos)%mCap];
  for(int i = 0 ; i < mSize-pos-1 ; i++){
    int tmp2  = mData[(idx-i-1+mCap)%mCap];
    mData[(idx-i-1+mCap)%mCap] = tmp;
    tmp = tmp2;
  }
}

#endif
