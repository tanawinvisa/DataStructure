#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
    while(true){
        // std::cout << idx<<std::endl;
        if(idx == 0) break;
        // std::cout << (idx-1)/4 <<mData[idx] << mData[(idx-1)/4] << std::endl;
        if(!mLess(mData[idx] ,mData[(idx-1)/4])){
            T a = mData[(idx-1)/4];
            mData[(idx-1)/4] = mData[idx];
            mData[idx] = a;
            idx = (idx-1)/4;
        }else{
            break;
        }
    }
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    while(4*idx+1< mSize){
        // std::cout <<idx<<std::endl;
        bool c = false;
        if(4*idx +1< mSize) if(mLess(mData[idx],mData[4*idx+1])) c =true;
        if(4*idx+2 < mSize) if(mLess(mData[idx],mData[4*idx+2])) c =true;
        if(4*idx+3 < mSize) if(mLess(mData[idx],mData[4*idx+3])) c =true;
        if(4*idx+4 < mSize) if(mLess(mData[idx],mData[4*idx+4])) c =true;
        int tmp = idx;
        if(4*idx+1 < mSize) if (mLess(mData[idx],mData[4*idx+1])) tmp = 4*idx+1;
        if(4*idx+2 < mSize) if (mLess(mData[tmp],mData[4*idx+2])) tmp = 4*idx+2;
        if(4*idx+3 < mSize) if (mLess(mData[tmp],mData[4*idx+3])) tmp = 4*idx+3;
        if(4*idx+4 < mSize) if (mLess(mData[tmp],mData[4*idx+4])) tmp = 4*idx+4;

        if(c){
                T a = mData[tmp];
                mData[tmp] = mData[idx];
                mData[idx] = a;
        }else{
            break;
        }
        if(idx == tmp) break;
        idx = tmp;
        
    }
}

#endif

