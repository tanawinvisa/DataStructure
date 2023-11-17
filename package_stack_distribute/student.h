#ifndef __STUDENT_H__
#define __STUDENT_H__
using namespace std;
#include <vector>
#include <algorithm>

template <typename T>
std::vector<std::vector<T> > CP::stack<T>::distribute(size_t k) const {
  //write your code here
  vector<int> v(k);
  vector<vector<T> > ans(k);
  CP::stack<T> tmp;
  tmp = *this;
  for(int i = 0 ; i < size() ; i++){
    v[i%k] += 1;
  }
  for(int i = 0 ; i < v.size() ; i++){

    for(int j = 0 ; j < v[i]; j++){
      T a = tmp.top();
      tmp.pop();
      ans[i].push_back(a);
    }

  }
  return ans;
}
#endif
