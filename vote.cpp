#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, K;
    int p;
    cin >> N >> K;
    map<string,int> m;
    map<int, vector<string> > mv;
    string s;
    int x;
    for(int i = 0 ; i < N ; i++){
        cin >> s ;
        if(m.find(s) != m.end()){
            m[s]++;
        }else{
            m[s] = 1;
        }
    }
    for(auto it = m.begin() ; it != m.end() ; it++){
        if(mv.find(it->second) != mv.end()){
            mv[it->second].push_back(it->first);
        }else{
            vector<string> v;
            v.push_back(it->first); 
            mv[it->second] = v;
        }
    }
    if(m.size() <= K){
        auto it = min_element(mv.begin() , mv.end());
        p = it->first;
    }else{
        int c = 0;
        for(auto it= mv.rbegin() ; it != mv.rend() ; it++){
            c += (it->second).size();
            if(c >= K){
                p = it->first;
                break;
            }
        }
    }
    cout << p;
}