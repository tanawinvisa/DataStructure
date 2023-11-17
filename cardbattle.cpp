#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
         std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n , m ;
    cin >> n >> m;
    map<int , int> toe;
    int c;
    for(int i = 0 ; i < n ; i++){
        cin >> c;
        toe[c]++;
    }
    int t;
    for(int i = 0 ; i < m ; i++){
        cin >> t;
        int c;
        for(int j = 0 ; j < t ; j++){
            cin >> c;
            auto it = toe.upper_bound(c);
            if(it == toe.end()){
                cout << i+1;
                return 0;
            }
            toe[it->first]--;
            if(it->second == 0){
                toe.erase(it);
            }
            if(toe.empty()){
                cout << i+1;
                return 0;
            }

        }
    }
    cout << m + 1;
}

// 5 3
// 10 10 10 10 10 1 1
// 1 2
// 1 3

// 5 3
// 10 10 10 10 10 1 100
// 1 1
// 1 2

// 7 3 5 4 1 3 5 1 1 3 4 4 3
// 1 1
// 1 1