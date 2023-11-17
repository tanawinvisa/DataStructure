#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n , m ,k;


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    cin >> n >> m >> k;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    sort(v.begin() , v.end());
    int x,c;
    int xmin,xmax;
    for(int i = 0 ; i < m ; i++){
        c = 0;
        cin >> x;
        xmin = x-k;
        xmax = x+k;
        auto itmin = lower_bound(v.begin() , v.end() , xmin);
        auto itmax = upper_bound(v.begin() , v.end() , xmax);
        cout << itmax - itmin << " ";
        
    }
}
