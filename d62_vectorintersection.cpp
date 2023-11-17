#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
    int N , M;
    cin >> N >> M;
    set<int> s1;
    set<int> s2;
    vector<int> v;
    int x;
    for(int i = 0 ; i< N ; i++){
        cin >> x;
        s1.insert(x);
    }
    for(int i = 0 ; i < M ; i++){
        cin >> x;
        s2.insert(x);
    }
    set_intersection(s1.begin() , s1.end() , s2.begin() , s2.end() , std::back_inserter(v));

    for(auto &x: v){
        cout << x << " ";
    }
    
}