#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    int res = mCap - mSize;
    int otherres = other.mCap - other.mSize;
    int a = otherres - res;
    if(a < 0)return 1;
    if(a == 0) return 0;
    if(a > 0) return -1;
}

#endif
