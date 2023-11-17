#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N,M;
map<int , int> m ;
bool ps(int x){
    for(auto it = m.begin() ; it != m.end() ; it++){
        int d = x - it->first;
        if((m.find(d) != m.end()) && (m.find(d) != it)){
            return true;
        }
    }
    return false;

}

int main() {
    cin >> N >> M;
    int x;
    for(int i = 0 ; i < N ; i++){
        cin >> x;
        if(m.find(x) == m.end()){
            m[x] = 1;
        }else{
            m[x]++;
        }
    }
    for(int i = 0 ; i < M ; i++){
        cin >> x;
        if(ps(x)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}