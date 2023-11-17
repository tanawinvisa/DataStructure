#include <iostream>
#include <algorithm>

using namespace std;

void check(int a , int b){
    if(a == b) {cout << "a and b are the same node\n";
        return ;
    }

    if(a < b){
        while(true){
            b = (b-1)/2;
            if(b == a){
                cout << "a is an ancestor of b\n";
                return ;
            }
            if(b == 0){
                cout <<  "a and b are not related\n";
                return;
            }

        }
    }
    if(b < a){
        while(true){
            a = (a-1)/2;
            if(b == a){
                cout << "b is an ancestor of a\n";
                return ;
            }
            if(a == 0){
                cout <<  "a and b are not related\n";
                return;
            }

        }
    }
}

int main(){
    int n , m;
    cin >> n >> m;
    int a, b;
    for(int i = 0 ; i < m; i++){
        cin >> a >> b;
        check(a,b);
    }
    
}