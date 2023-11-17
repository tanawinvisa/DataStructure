#ifndef __STUDENT_H__
#define __STUDENT_H__
using namespace std;
#include <stack>

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  expand(mSize+m);
  stack<T> st;
  for(int i = 0 ; i< k ; i++){
    T a = top();
    pop();
    st.push(a);
  }
  
    if( m >= s2.size()){
      for(int i = 0 ; i < s2.size() ; i++){
        push(s2.mData[i]);
      }
      s2.mSize = 0;
    }else{
      for(int i = 0 ; i < m ; i++){
        push(s2.mData[s2.mSize-m+i]);
      }
      s2.mSize -= m;
    }

  while(!st.empty()){
    T a = st.top();
    push(a);
    st.pop();
  }
}
#endif
