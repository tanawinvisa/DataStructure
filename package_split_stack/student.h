#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
std::vector<std::vector<T> >  CP::stack<T>::split_stack(int k) const {
  //your code here
  //should return something
  CP::stack<T> tmp ;
  tmp = *this;
  vector<vector<T> > ans(k);
  int idxst = 0;
  while(!tmp.empty()){
    T a = tmp.top();
    tmp.pop();
    ans[idxst%k].insert(ans[idxst%k].begin(),a);
    idxst++;
  }
  return ans;
}

#endif

