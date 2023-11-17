#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int,int> &v, int pos, int value) {
  //your code here
  auto posit = v.lower_bound(pos);
  vector<pair <int , int > > vp;
  vp.push_back(make_pair(pos,value));
  for(auto it = posit ; it != v.end() ; it++){
    vp.push_back(make_pair(it->first +1 , it->second));
  }
  v.erase(posit , v.end());
  v.insert(vp.begin() , vp.end());
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  map<int,int> v;
  cin >> n;
  for (int i = 0;i < n;i++) {
    int a,b;
    cin >> a >> b;
    insert_into_sv(v,a,b);
}
  cout << v.size() << "\n";
  for (auto &x : v) {
    cout << x.first << ": " << x.second << "\n";
  }
}

// 5
// 2 10
// 5 99
// 6 30
// 11 7
// 12 8