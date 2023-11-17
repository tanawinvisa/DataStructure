#include <iostream>
#include <algorithm>

using namespace std;

bool one( long long a ,  long long b){
    if( a < b){
        if((b-1)/2 == a) return true;
    }
    if( b < a){
        if((a-1)/2 == b) return true;
    }
    return false;
}

bool two( long long a ,  long long b){
    if(a < b){
        while(a < b){
            b = (b-1)/2;
            if(b == a){
                return true;
            }
        }
    }
    if(b < a){
        while(b < a){
            a = (a-1)/2;
            if(b == a){
                return true;
            }
        }
    }
    return false;
}

bool three( long long a,  long long b){
     long long ia = 0;
     long long ib = 0;
    while( a > 0){
        a = (a-1)/2;
        ia++;
    }
    while( b > 0){
        b = (b-1)/2;
        ib++;
    }
    if(ia == ib) return true;
    else return false;
}

int main(){
    long long n;
    cin >> n;
    long long a ,b;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b;
        if(one(a,b)){
            cout << 1 << " ";
            continue;
        }
        if(two(a,b)){
            cout << 2 << " ";
            continue;
        }
        if(three(a,b)){
            cout << 4 << " ";
            continue;
        }else{
            cout << 3 << " ";
            continue;
        }
    }

}