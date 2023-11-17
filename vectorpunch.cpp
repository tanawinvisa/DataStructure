#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
    vector<string> v1;
    int index_v = it - v.begin();
    for(int i = 0  ; i < v.size() ; i++){
        if((i < index_v-k) || (i > index_v+k)){
            v1.push_back(v[i]);
        }
    }
    return v1;
}
int main() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i]; 
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result) {
        cout << x << endl;
    }
}
  