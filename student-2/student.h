#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  // Your code here
  // std::cout <<"asdasdsd" <<mFront << "asdasd\n";
  if(aux== 1){
    aux = 0;
  }else{
    aux = 1;
  }
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
  if(aux == 1){
    return mData[(mFront + mSize - 1) % mCap];
  }
  return mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  if(aux == 1){
    return mData[mFront];
  }
  return mData[(mFront + mSize - 1) % mCap];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // You MAY need to edit this function
  ensureCapacity(mSize + 1);
  if(aux == 0){
    mData[(mFront + mSize) % mCap] = element;
    mSize++;
  }else{
    mData[(mFront -1 + mCap) % mCap] = element;
    mSize++;
    mFront--;
    mFront = (mFront + mCap)%mCap;
  }
  // for(int i = 0 ; i < size() ; i++){
  //     std::cout << mData[i];
  //   }
  //   std::cout << std::endl<<mFront <<"\n";
  
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  if(aux == 0){
    mFront = (mFront + 1) % mCap;
    mSize--;
  }else{
    mSize--;
  }
  
}

#endif