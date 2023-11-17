#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n , m ;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    int p = 0;
    int i = 0;
    while( p != m){
        for(int j = 0 ; j < n ; j++){
            if(i % v[j] == 0){
                cout << i << "\n";
                p++;
                if(p == m){
                    break;
                }
            }
        }
        i++;
    }
}