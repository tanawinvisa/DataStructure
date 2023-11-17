#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once
#include <vector>
#include <queue>
#include "queue.h"

template <typename T>
std::vector< CP::queue<T> > CP::queue<T>::split_queue(int k) {
    std::vector<CP::queue<T> > qs(k);
    int f = mFront;
    for(int i = 0 ; i < size() ; i++){
        qs[(i)%k].push(mData[(i+mFront)%mCap]);
    }
    T * arr = new T[0];
    mCap = 1;
    mSize = 0;
    mFront = 0;
    return qs;
}

#endif

