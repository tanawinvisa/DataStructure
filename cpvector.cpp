#ifndef _CP_VECTOR_INCLUDED_
#define _CP_VECTOR_INCLUDED_

#include <stdexcept>
#include <iostream>
#include <map>
//#pragma once
using namespace std;

namespace CP { 

template <typename T>
class vector
{
  public:
    typedef T* iterator;

  public:
    T *mData;
    size_t mCap;
    size_t mSize;

    void rangeCheck(int n) {
      if (n < 0 || (size_t)n >= mSize) {
        throw std::out_of_range("index of out range") ;
      }
    }

    void expand(size_t capacity) {
      T *arr = new T[capacity]();
      for (size_t i = 0;i < mSize;i++) {
        arr[i] = mData[i];
      }
      delete [] mData;
      mData = arr;
      mCap = capacity;
    }

    void ensureCapacity(size_t capacity) {
      if (capacity > mCap) {
        size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
        expand(s);
      }
    }

  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    vector(const vector<T>& a) {
      mData = new T[a.capacity()]();
      mCap = a.capacity();
      mSize = a.size();
      for (size_t i = 0;i < a.size();i++) {
        mData[i] = a[i];
      }
    }

    // default constructor
    vector() {
      int cap = 1;
      mData = new T[cap]();
      mCap = cap;
      mSize = 0;
    }

    // constructor with initial size
    vector(size_t cap) {
      mData = new T[cap]();
      mCap = cap;
      mSize = cap;
    }

    // copy assignment operator using copy-and-swap idiom
    vector<T>& operator=(vector<T> other) {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be descructed
      using std::swap;
      swap(this->mSize, other.mSize);
      swap(this->mCap, other.mCap);
      swap(this->mData, other.mData);
      return *this;
    }

    ~vector() {
      delete [] mData;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }

    size_t capacity() const {
      return mCap;
    }

    void resize(size_t n) {
      if (n > mCap)
        expand(n);

      if (n > mSize) {
        T init = T();
        for (size_t i = mSize;i < n;i++) 
          mData[i] = init;
      }


      mSize = n;
    }

    //----------------- iterator ---------------
    iterator begin() {
      return &mData[0];
    }

    iterator end() {
      return begin()+mSize;

    }
    //----------------- access -----------------
    T& at(int index) {
      rangeCheck(index);
      return mData[index];
    }

    T& at(int index) const {
      rangeCheck(index);
      return mData[index];
    }

    T& operator[](int index) {
      return mData[index];
    }

    T& operator[](int index) const {
      return mData[index];
    }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(),element);
    }

    void pop_back() {
      mSize--;
    }

    iterator insert(iterator it,const T& element) {
      size_t pos = it - begin();
      ensureCapacity(mSize + 1);
      for(size_t i = mSize;i > pos;i--) {
        mData[i] = mData[i-1];
      }
      mData[pos] = element;
      mSize++;
      return begin()+pos;
    }

    void erase(iterator it) {
      while((it+1)!=end()) {
        *it = *(it+1);
        it++;
      }
      mSize--;
    }

    void clear() {
      mSize = 0;
    }


    //-------------- extra (unlike STL) ------------------
    void insert_by_pos(size_t it,const T& element) {
      insert(begin()+it,element);
    }

    void erase_by_pos(int index) {
      erase(begin()+index);
    }

    void erase_by_value(const T& element) {
      int i = index_of(element);
      if (i != -1) erase_by_pos(i);
    }

    bool contains(const T& element) {
      return index_of(element) != -1;
    }

    int index_of(const T& element) {
      for (int i = 0;i < mSize;i++) {
        if (mData[i] == element) {
          return i;
        }
      }
      return -1;
    }

    void unique(){
        T * newData = new T[mCap]();
        int idx = 1 ;
        newData[0] = mData[0];
        for(int i = 1 ; i < mSize ; i++){
            if(mData[i] != mData[i-1]){
                newData[idx++] = mData[i];
            }
        }
        delete [] mData;
        mData = newData;
        mSize = idx;
    }
};

}

#endif

int main() {
    CP::vector<int> v;
    auto it = v.begin();
    for(int i = 0 ; i < 30 ; i++){
        if(i == 16){
            it = v.begin();
            std::cout << "here";
        }
        v.insert(v.begin(),1);
        // std::cout<<*it<<std::endl;
        // std::cout << &it << std::endl;
        // std::cout << &(*v.begin()) << std::endl;
        // std::cout << v.mCap<<std::endl;
    }
    // std::cout << *it;
    // std::cout << v.mCap;

    map<int , string> m;
    m[1]='a';
    m[2]='b';
    for(auto &e : m){
        cout << e.second;
    }

    CP::vector<int> v21;
    v21.push_back(1);
    v21.push_back(2);
    v21.push_back(2);
    v21.push_back(4);
    v21.push_back(4);
    v21.push_back(1);
    v21.push_back(1);
    v21.push_back(1);
    v21.push_back(1);
    v21.push_back(2);
        v21.push_back(9);
    v21.push_back(8);
    v21.push_back(9);
    cout << endl;
    v21.unique();
    for(auto &e : v21){
        cout << e;
    }
    cout << endl;
    cout << v21.mCap;
    cout << v21.size();
    cout << endl;

    for(auto &e : v21){
        if(e == 1){
            auto it = find(v21.begin() , v21.end() , e);
            v21.erase(it);
        }
    }

    for(auto &e : v21){
        cout << e;
    }
}