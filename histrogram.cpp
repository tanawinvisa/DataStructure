#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N ;
    cin >> N;
    string s ;
    map<string , int> m ;
    for(int i = 0 ; i< N ; i++){
        cin >> s;
        m[s]++;
    }
    for(auto it = m.begin() ; it != m.end() ;it++){
        if(it->second >1){
            cout << it->first << " " << it->second << "\n";
        }
    }
}