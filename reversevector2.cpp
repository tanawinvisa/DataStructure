#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
  //write your code only in this function
  int istart = a-v.begin();
  int istop =   b-v.begin();
  vector<int> v2(a,b);
  int j = 0;
  for(int i = istart; i < istop ; i++){
    v[istop-1-j] = v2[j];
    j++;
  }
  
}
int main() {
  //read input
  int n,a,b;
  cin >> n;
  vector<int> v;
  for (int i = 0;i < n;i++) {
    int c;
    cin >> c;
    v.push_back(c);
}
cin >> a >> b;
  //call function
  reverse(v,v.begin()+a,v.begin()+b+1);
  //display content of the vector
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << endl;
}