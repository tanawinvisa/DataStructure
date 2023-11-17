#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {
  if(mSize != other.size()) return false;

  CP::priority_queue<T ,Comp> pq1(*this);
  CP::priority_queue<T ,Comp> pq2(other);
  int s = mSize;
  while(s--){
    if(pq1.top() != pq2.top()){
      return false;
    }
    return true;
  }


  //write your code here
  return true; // you can change this line
}

#endif
