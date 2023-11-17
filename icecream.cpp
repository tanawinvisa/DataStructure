#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n , m , start;
    map<int , int > mp;
    vector<int> arr(100010);


    cin >> n >> m >> start;
    int a , s;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> s;
        mp[a] = s;
    }
    int P , x;

    int sum = 0;
    int start1 = start;
    for(int i = 0 ; i < 100010 ; i++){
        auto it = mp.find(i);
        if(it != mp.end()){
                start1 = it->second;
                sum += start1;
                arr[i] = sum;
        }else{
            sum += start1;
            arr[i] = sum;
        }
    }

    // cout << endl;
    // for(int i = 0 ; i < 100009 ; i++){
    //     cout << arr[i] << " ";
    // }cout << endl;
    
    for(int i  = 0 ; i < m ; i++){
        cin >> P >> x;
        auto ans = arr.begin();
        if(arr[x] >= P){
            ans = lower_bound(arr.begin() , arr.begin() + x+1 , P);
        }else{
            ans = lower_bound(arr.begin() , arr.begin() + 100009 , P + arr[x]);
        }
        cout << ans-arr.begin() << " ";
    }

    
}

/*
2 7 3 4 2
6 5
1 1000 3 1000 4 1000 12 1000 13 1000 14 1000 15 1000

2 5 3
4 2 
6 5 
11 3 12 3 13 3 200 4 200 5

3 3 20
400 15
35 80
500 30 120457 5000 120457 3000 3016390 1
*/