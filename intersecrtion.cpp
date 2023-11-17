#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N , M;
    cin >> N >> M;
    vector<int> v1(N) ,v2(M);
    vector<int> v,ans;
    int x;
    for(int i = 0 ; i < N ; i++){
        cin >> v1[i];
    }
    sort(v1.begin() , v1.end());

    for( int i = 0 ; i < M ; i++){
        cin >> x;
        auto it = lower_bound(v1.begin() , v1.end() , x);
        if( (*it == x) && (find(v.begin() , v.end() , x) == v.end())){
            v.push_back(*it);
        }
    }
    sort(v.begin() , v.end());  


    for(auto &x : v){
        cout << x << " ";
    }

    
}