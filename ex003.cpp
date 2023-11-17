#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
map<int ,int> m ;


int main(){
    int N;
    cin >> N;
    int x ; 
    set<int> s1 ,s2;
    for(int i = 1 ; i <= N ; i++){
        cin >> x;
        m[i] = x;
        if(x > N){
            cout << "NO";
            return 0;
        }
        if(x <= 0){
            cout << "NO";
            return 0;
        }
        s1.insert(i);
        s2.insert(x);
    }
    if(s1.size() != s2.size()) {
        cout << "NO";
        return 0;
    }
    if(s1 != s2){
        cout << "NO";
        return 0;
    }
    cout <<"YES";


}