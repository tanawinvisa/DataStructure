#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
    int idx = (mFront-1+mCap)%mCap;
    int tmp = mData[(pos+mFront)%mCap];
    for(int i = 0 ; i < mSize-pos-1 ; i++){
        mData[(pos+i+mFront)%mCap] = mData[(pos + i + 1+mFront)%mCap];
    }
    mData[idx] = tmp;
    mFront =idx;
}

#endif
