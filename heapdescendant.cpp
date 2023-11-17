#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n;
set<int> s;

void f(int a){
    if(a < n){
        s.insert(a);
        f(a*2+1);
        f(a*2 + 2);
    }else{
        ;
    }
}

int main(){
    int a;
    cin >> n >> a;
    f(a);
    cout << s.size()<<"\n";
    for(auto e : s){
        cout << e << " ";
    }
}