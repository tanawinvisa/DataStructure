#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

bool check(long long mFront , long long mSize , long long mCap , long long last){
    if(mSize <= mCap){

            }else{
                return false;
            }

            if((mFront + mSize)%mCap == last){

            }else{
                return false;
            }
            if(mFront >= mCap){
                return false;
            }
            if(last >= mCap){
                return false;
            }
            return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n ;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        long long mFront , mSize , mCap ,last , correction;
        cin >> mFront >> mSize >> mCap >> last >> correction;
        if(correction == 0){
            if(check(mFront , mSize , mCap ,last )){
                cout << "OK\n";
            }else{
                cout << "WRONG\n";
            }
        }else if (correction == 1){
            if(check(mFront , mSize , mCap ,last )){
                cout << "OK\n";
            }else{
                mFront = ((last - mSize+mCap)%mCap + mCap)%mCap;
                cout << "WRONG " << mFront << "\n";
            }
        }else if (correction == 2){ 
            if(check(mFront , mSize , mCap ,last )){
                cout << "OK\n";
            }else{
                mSize = ((last - mFront +mCap)%mCap + mCap)%mCap;
                cout << "WRONG " << mSize << "\n";
            }
        }else if (correction == 3){
            if(check(mFront , mSize , mCap ,last )){
                cout << "OK\n";
            }else{
                
            mCap = (mFront < last)? mSize + mFront + 1: mFront - last + mSize;

                cout << "WRONG " << mCap << "\n";
            }
        }else {
            if(check(mFront , mSize , mCap ,last )){
                cout << "OK\n";
            }else{
                last = (mFront + mSize)%mCap;
                cout << "WRONG " << last << "\n";
            }
        }
    }
    
}