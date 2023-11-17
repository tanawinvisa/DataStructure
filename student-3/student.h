#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <map>
#include <algorithm>

using namespace std;

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator> > &ranges) {
  // Write code here
  sort(ranges.begin() , ranges.end());
  map<int,int> m;  
  int idxr = 0;
  int i = 0;
  vector<T> tmp;
  while( i< size()){
    // cout << i << endl;
    if(i < ranges[idxr].first - begin()){
      for(int j = i ; j < ranges[idxr].first - begin() ; j++){
        m[j]++;
      }
      i =  ranges[idxr].second - begin();
    }else{
      if(i >= ranges[idxr].second - begin()){
        ;
      }else{
        i =  ranges[idxr].second - begin();
      }
    }
    if(i >= ranges[ranges.size() -1].second - begin()){
      for(int j = i ; j < size() ; j++){
        m[j]++;
      }
      break;
    }
    idxr++;
  }
  for(int i = 0 ; i < size() ; i++){
    if(m[i] != 0){
      tmp.push_back(mData[i]);
    }
  }
  *this = tmp;
}

#endif
