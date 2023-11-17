#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
  while(K--){
    pop();
    if(size() == 0) break;
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  //
  //don't forget to return an std::stack
  std::stack<T> s1 , s2;
  while(K--){
    T a = top();
    pop();

    s1.push(a);
    if(size() == 0) break;
  }
  while(!s1.empty()){
    T a = s1.top();
    s2.push(a);
    s1.pop();
  }
  return s2;
}

#endif
