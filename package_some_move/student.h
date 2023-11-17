#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
if(index >= mSize) {
        int ii = mData.size() - 1;
        for(auto e:value) {
            mData[ii].push_back(e);
        }
        mSize += value.size();
        aux[ii] += value.size();
        mCap = std::max(mCap, mSize);
        return;
    }

  int i = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
    if (i > 0)
      index -= aux[i - 1];
    // return mData[i][idx];
  for(int j = 0 ; j < value.size() ; j++){
    mData[i].insert(mData[i].begin() + index , value[value.size()-1 - j ]);
  }
  mSize += value.size();
  mCap += value.size();
  for(int j = 0 ; j < mData.size() ; j++){
    if(j == 0){
      aux[0] = mData[j].size();
    }else{
      aux[j] = aux[j-1] + mData[j].size();
    }
  }

}

#endif