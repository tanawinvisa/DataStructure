#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  T mn;
  bool b = true;
  for(int i = 0 ; i < pos.size(); i++){
    if(pos[i] >= mSize) continue;
    

    if(b){
      b = false;
      mn = mData[(pos[i] + mFront)%mCap];
    }else{
      if(!comp(mn,mData[(pos[i] + mFront)%mCap])){
        mn = mData[(pos[i] + mFront)%mCap];
      }
    }

  }
  //should return something
  return mn;
}

#endif
