#include <iostream>
#include <vector>
using namespace std;
int relation(long long S, long long a, long long b) {
    
    bool one( long long a ,  long long b, long long S){
    if( a < b){
        if((b-1)/S == a) return true;
    }
    if( b < a){
        if((a-1)/S == b) return true;
    }
    return false;
}

bool two( long long a ,  long long b, long long S){
    if(a < b){
        while(a < b){
            b = (b-1)/S;
            if(b == a){
                return true;
            }
        }
    }
    if(b < a){
        while(b < a){
            a = (a-1)/S;
            if(b == a){
                return true;
            }
        }
    }
    return false;
}

bool three( long long a,  long long b, long long S){
     long long ia = 0;
     long long ib = 0;
    while( a > 0){
        a = (a-1)/S;
        ia++;
    }
    while( b > 0){
        b = (b-1)/S;
        ib++;
    }
    if(ia == ib) return true;
    else return false;
}

if(one(a,b,S)){
            cout << 1 << " ";
        }else{
            if(two(a,b,S)){
            cout << 2 << " ";
        }else{
            if(three(a,b,S)){
            cout << 4 << " ";
            ;
            }else{
                cout << 3 << " ";
                ;
            }
        }
        }

}
int main() {
ios_base::sync_with_stdio(false); cin.tie(0); int n;
long long S,a,b;
cin >> n;
while (n--) {
    cin >> S >> a >> b;
cout << relation(S,a,b) << " "; }
  cout << endl;
}