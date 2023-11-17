#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Q;
vector<int> v;

int main() {    
    cin >> Q;
    for(int i = 0 ; i < Q ; i++){
        string s;
        int x;
        cin >> s;
        if( s == "pb"){
            cin >> x;
            v.push_back(x);
        }else if (s == "sa"){
            sort(v.begin() , v.end());
        }else if (s == "sd"){
            sort(v.begin() , v.end());
            vector<int> v1;
            for(auto it = v.rbegin() ; it != v.rend() ; it++){
                v1.push_back(*it);
            }
            v = v1;
        }else if (s == "r"){
            vector<int> v1;
            for(auto it = v.rbegin() ; it != v.rend() ; it++){
                v1.push_back(*it);
            }
            v = v1;
        }else if(s == "d"){
            cin >> x;
            v.erase(v.begin() + x);
        }
    }
    for( auto &e : v){
        cout << e << " ";
    }
}