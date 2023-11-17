#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    map<string,int> m;
    int N;
    cin >> N;
    string s;
    for(int i = 0 ; i < N ; i++){
        cin >> s;
        if(m.find(s) == m.end()){
            m[s] = 1;
        }else{
            m[s]++;
        }
    }
    int mx = 0;
    string keymx ;
    for(auto it = m.begin() ; it != m.end() ; it++){
        if(it->second >= mx) {
            keymx = it->first;
            mx = it->second;
            }
    }

    cout << keymx << " " << mx;

}