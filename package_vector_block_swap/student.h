#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <vector>
using namespace std;

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  int posa = a- begin();
  int posb = b-begin();
  auto posmin = min(posa,posb);
  auto posmax = max(posa,posb);
  if(m <= 0) return false;
  if(begin() <= a &&  a < end()){
  }else{ return false;}
  if(begin() <= b &&  b < end()){
  }else{ return false;}
  if(posmin + m -1 >= posmax) return false;
  if(posmax + m -1 >=  size()) return false;
  vector<T> v(m);
  for(int i = 0 ; i < m ; i++){
    v[i] = mData[posmin + i ];
    mData[posmin + i ] = mData[posmax + i ];
  }
  for(int i = 0 ; i < m ; i++){
    mData[posmax + i ] = v[i];
  }

  return true;
}

#endif
