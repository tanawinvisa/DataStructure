#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) { //write your code here
    vector<int> v2(v.size() + count);
    int idxv2 = 0;
    int idxv = 0;
    int count2 = count;
    while(idxv2 < (v.size() + count)){
        if(idxv2 == position){
            while(count2--){
                v2[idxv2++] = value;
            }
        }else{
            v2[idxv2++] = v[idxv++];
        }
    }
    v = v2;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
int n,value,position,count;
cin >> n >> value >> position >> count; vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];
multiple_add(v,value,position,count);
  cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
  for (auto &x : v) cout << x << " ";
  cout << endl;
 }
 