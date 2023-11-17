#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int f(int x , int k){
    int s = x+k;
    if(s >=  26){
        s = s%26;
    }
    return s;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int L , M , N;
    cin >> N >> M >> L;
    string abc;
    abc = "abcdefghijklmnopqrstuvwxyz";
    map< char, int> mp ;
    for(int i = 0 ; i< 26 ; i++){
        char a = abc[i];
        mp[a] = i;
    }
    set<string> s;
    vector<int> v(L);
    for(int i = 0 ; i < L ; i++){
        cin >> v[i];
    }
    for(int i = 0 ; i < N ; i++){
        string p ;
        cin >> p;
        s.insert(p);
    }
    string p;
    for(int i = 0 ; i < M ; i++){
        string p2;
        cin >> p;
        for(int i = 0 ; i < L ; i++){
            p2 += abc[f( mp[p[i]],v[i] )];
        }
        auto it = s.find(p2);
        if(it == s.end()){
            cout << "Unknown\n";
        }else{
            cout << "Match\n";
        }
    }


}

