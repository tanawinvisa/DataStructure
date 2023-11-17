#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int N , M;
map<long long ,long long >m;  //m[son] = father

bool c(long long x , long long y){
    if(x==y) return false;
    if(m.find(x) == m.end() || m.find(y) == m.end()) return false;
    if(m.find(m[x]) == m.end() || m.find(m[y]) == m.end()) return false;
    // if(m[x] == m[y]) return false;
    if(m[m[x]] == m[m[y]]) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    long long x , y;
    for(int i = 0 ; i < N ; i++){
        cin >> x >> y;
        m[y] = x;
    }
    for(int i = 0 ; i < M ; i++){
        cin >> x >> y;
        if(c(x,y)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    
}