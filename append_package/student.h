#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        T * arr = new T[size() + s.size()];
        int idx = 0;
        for(int i = 0 ; i < s.size() ; i++){
            arr[i] = s.mData[i];
            idx = i;
        }
        for(int i = 0 ; i < size() ; i++){
            arr[idx + i + 1] = mData[i];
        }
        delete [] mData;
        mData = arr;
        mSize += s.size();

    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        T * arr = new T[size() + q.size()];
        int idx = q.size() -1;
        for(int i = 0 ; i < q.size() ; i++){
            arr[q.size()-1-i] = q.mData[(i+q.mFront)%q.mCap];
        }
        for(int i = 0 ; i < size() ; i++){
            arr[idx + 1 + i] = mData[i];
        }
        delete [] mData;
        mData = arr;
        mSize = size() + q.size();

    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        T * arr = new T[size() + s.size()];
        for(int i = 0 ; i < size() ; i++){
            arr[i] = mData[(i+mFront)%mCap];
        }
        int idx = size();
        for(int i = 0 ; i < s.size() ; i++){
            arr[idx + i] = s.mData[s.size()-i-1];
        }
        delete [] mData;
        mData = arr;
        mSize += s.size();
        mFront = 0;
        mCap = size() + s.size();
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while(!q.empty()){
            T a = q.front();
            q.pop();
            push(a);
        }
    }
}
