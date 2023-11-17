#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here
  //
  if(k >= size()){
    for(int i = 0 ; i < size() ; i++){
      T a = mData[(i + mFront)%mCap];
      res.push_back(a);
    }
  }else{
    for(int i = 0 ; i < k ; i++){
      T a = mData[(i + mFront)%mCap];
      res.push_back(a);
    }
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here
  T * arr = new T[to-from];
  mCap = to-from;
  mData = arr;
  mFront = 0;
  mSize = mCap;
  for(int i = 0 ; i < mSize ; i++){
   mData[i] = *(from+i);
  }

}

#endif
