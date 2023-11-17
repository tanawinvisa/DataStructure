#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
  //write your code here
  //
  // YOU CANNOT CALL push or pop
  if(size() != other.size()) return false;
  int idx = mFront;
  int idxo = other.mFront;
  int i = 0;
  while(mData[idx+i] == other.mData[idxo+i]){
    i++;
    if(i == size()) return true;
  }
  return false;
}

#endif
