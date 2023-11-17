#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n , m,a;
    cin >> n >> m;
    vector<int> v(n);//ค่าพลังทั้งหมด
    vector<int> v2(m,1); //ค่าประภาท index 0 = ประเภท 0
    map<int , int> mp;
    mp[1] = m;
    for(int i =0 ; i< n ; i++){
        cin >> v[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> a;
        if(v2[a] < v[i]){
            mp[v[i]]++;
            mp[v2[a]]--;
            if(mp[v2[a]] == 0){
                mp.erase(v2[a]);
            }
            v2[a] = v[i];
        }
        cout << mp.begin()->first << " ";
    }
}