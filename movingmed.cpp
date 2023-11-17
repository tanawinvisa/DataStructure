#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n , w;
    cin >> n >> w;
    vector<int> v(n);
    int m = (w+1)/2;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    if(n == w){
        cout << v[m];
    }else{
        vector<int> v2(v.begin() , v.begin() + w+1);
        sort(v2.begin() , v2.end());
        for(int i = 0 ; i < n-w ; i++){
            if(i != 0){
                auto it = lower_bound(v2.begin() , v2.end(),v[i-1]);
                v2.erase(it);
                auto it2 = lower_bound(v2.begin() , v2.end() , v[i+w]);
                v2.insert( it2 , v[i+w]);
            }
            cout << v2[m] << " ";
        }
    }
}

