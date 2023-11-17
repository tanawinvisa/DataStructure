#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  ensureCapacity(mSize +1);
  if(pos == 0){
    push(value);
  }else{
    int posinsert = mSize-pos;
    for(int i = mSize-1 ; i >= posinsert ; i--){
      mData[i+1] = mData[i];
    }
    mData[posinsert] = value;
    mSize += 1;
  }
}

#endif
