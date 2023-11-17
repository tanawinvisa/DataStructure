#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t> > CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
    std::map<T , int > m;
    for(int i = 0 ; i < k.size() ; i++){
        m[k[i]] = 0;
    }

    for(int i = 0 ; i < size() ; i++){
        if(m.find(mData[i]) != m.end()){
            m[mData[i]] += 1;
        }
    }
    std::vector<std::pair<T,size_t> > res(k.size());
    for(int i = 0 ; i < k.size() ; i++){
        res[i] = std::make_pair(k[i],m[k[i]]);
    }
    return res;
}

#endif
