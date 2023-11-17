#include <iostream>
#include <algorithm>
#include "math.h"

using namespace std;

long long b(long long i , long long r){
    int x = 1*(1-pow(r,i))/(1-r);
    return x;
}

int main(){
    long long n , k;
    cin >> n >> k;
    long long i = 1 ;
    long long a=  0;
    a = b(i ,k);
    while(n> a){
        cout << i;
        i++;
        a = b(i,k);
        
    }
    cout << i-1;




    if(k == 1){
        cout << n-1;
    }else{

    long long i = 0;
    while(1*(1-pow(k,i+1))/(1-k) < n){
        cout << "k" << i;
        i++;
    }
    cout << i;

}


    
}