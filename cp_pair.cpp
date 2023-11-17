#ifndef _CP_PAIR_INCLUDED_
#define _CP_PAIR_INCLUDED_

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


namespace CP {
    template <typename T1 ,typename T2>
    class pair{
        public: 
            T1 first;
            T2 second;

            pair() : first() , second() {}

            pair(const T1& a , const T2& b) : first(a) , second(b) {}
            
            bool operator==(const pair<T1, T2>& other) {
                return (first == other.first && second == other.second);
            }

            void a(){
                pair<T1,T2> p(this);

            }

            bool operator<(const pair<T1, T2>& other) const {
                if(first == other.first){
                    return second > other.second;
                }else{
                    return first > other.first;
                }
            }

            bool operator!=(const pair<T1,T2> & other) {
                return (first != other.first || second != other.second);
            }

            bool operator>=(const pair<T1, T2> & other) const{
                if(first < other.first){
                    return false;
                }else{
                    if(second < other.second){
                        return false;
                    }else{
                        return true;
                    }
                }
            }
    };
}
#endif


int main(){
    std::vector<CP::pair<int,int> > v;
    CP::pair<int ,int > p(1,2);
    CP::pair<int ,int > p2(3,4);
    CP::pair<int ,int > p3(1,3);


    v.push_back(p2);
    v.push_back(p);
    sort(v.begin() , v.end());
    for(auto &x : v){
        cout << "{" << x.first <<  x.second << "}" <<endl;
    }
    cout << (p3 >= p) ;
    cout << (p >= p3);
    cout << endl;
    cout <<((-5)%6 + 6);
}