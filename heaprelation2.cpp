#include <iostream>
#include <algorithm>

using namespace std;

bool one( long long a ,  long long b, long long s){
    if( a < b){
        if((b-1)/s == a) return true;
    }
    if( b < a){
        if((a-1)/s == b) return true;
    }
    return false;
}

bool two( long long a ,  long long b, long long s){
    if(a < b){
        while(a < b){
            b = (b-1)/s;
            if(b == a){
                return true;
            }
        }
    }
    if(b < a){
        while(b < a){
            a = (a-1)/s;
            if(b == a){
                return true;
            }
        }
    }
    return false;
}

bool three( long long a,  long long b, long long s){
     long long ia = 0;
     long long ib = 0;
    while( a > 0){
        a = (a-1)/s;
        ia++;
    }
    while( b > 0){
        b = (b-1)/s;
        ib++;
    }
    if(ia == ib) return true;
    else return false;
}

int main(){
    long long n;
    cin >> n;
    long long a ,b ,s;
    for(int i = 0 ; i < n ; i++){
        cin >>s >> a >> b;
        if(one(a,b,s)){
            cout << 1 << " ";
        }else{
            if(two(a,b,s)){
            cout << 2 << " ";
        }else{
            if(three(a,b,s)){
            cout << 4 << " ";
            ;
            }else{
                cout << 3 << " ";
                ;
            }
        }
        }
    }

}
// 3 2 0 1 2 1 0 2 8 1 
// 3 2 4 2 2 5 5 2 6 3 