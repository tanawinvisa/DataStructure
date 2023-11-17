#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    vector<int>v(m);
    vector<int>v2(m,-1);
    vector<int> money;
    int sum = 0;
    queue<int> A;
    queue<int> B;
    int a = 0;
    for(int i = 0 ; i < m ; i++){
        cin >> a;
        v[i] = a;
    }
    int b ,c;

    for(int i = 0; i < n ; i++){
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            if(b == 1){
                A.push(c);
            }else{
                B.push(c);
            }
        }else{
            if(A.empty()){
                a = B.front();
                B.pop();
            }else if( B.empty()){
                a = A.front();
                A.pop();
            }else{
                if(A.front() <= B.front() ){
                    a= A.front();
                    A.pop();
                }else{
                    a = B.front();
                    B.pop();
                }
            }
            sum += a;
            money.push_back(sum);
        }

    }
    for (int x : v) {
        if (x > *(money.end() - 1)) {
            cout << -1 << " ";
        } else {
            auto it = lower_bound(money.begin(), money.end(), x);
            cout << it - money.begin() + 1 << " ";
        }
    }

}


