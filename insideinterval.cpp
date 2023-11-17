#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    map<int , int> mp ;
    int n , m;
    cin >> n >> m;
    int x,y;
    for(int i = 0 ; i < n ; i++){
        cin >> x >> y;
        mp[x] = y;
    }

    for(int i = 0 ; i < m ; i++){
        cin >> x;
        auto it = mp.lower_bound(x);
        auto it1 = it;
        if(it == mp.begin()){
            if(it->first <= x){
                cout << "1 ";
                continue;
            }else{
                cout << "0 ";
                continue;
            }
        }
        it1--;
        
        if(it == mp.end()){
            if(it1->second >= x){ 
                cout << "1 ";
            }else{
                cout << "0 ";
            }
            continue;
        }

        if(x < it->first){
            if(it1->second >= x){
                cout << "1 ";
                
            }else{
                cout << "0 ";
            }
            continue;
        }else{
            cout << "1 ";
            continue;
        }

    }
}