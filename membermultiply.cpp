#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void member_multiply(vector<int> &v, vector<pair<vector<int>::iterator,int> > &multiply) {
  //write your code here
  int newvsize = v.size();
  for(auto it = multiply.begin() ; it != multiply.end() ; it++){
    newvsize += (*it).second;
  }
  vector<int> v2(newvsize);
  sort(multiply.begin() , multiply.end());
  int idx_mul = 0;
  int idx_newv = 0;
  for(int i = 0 ; i < v.size() ; i++){
    v2[idx_newv++] = v[i];
    if(i == multiply[idx_mul].first-v.begin()){
        for(int j = 0 ; j < multiply[idx_mul].second ; j++){
            v2[idx_newv++] = v[i];
        }
        idx_mul++;
    }
  }
  v = v2;
}
int main() { 
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n); vector<pair<vector<int>::iterator,int> > multiply(m); for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) {
    int a,b;
    cin >> a >> b; multiply[i].first = v.begin()+a; multiply[i].second = b;
    } member_multiply(v,multiply);
    cout << "======= result ========" << endl; cout << v.size() << endl;
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}