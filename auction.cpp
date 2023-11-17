#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N , M , A;
    cin >> N >> M >> A ; // N ของ N ชิ้น M คน A bid
    vector<int> amount(N+1);
    map<int ,  map<int , int> > m;
    map<int , vector<int> > usergot;
    for(int i = 1 ; i< N+1 ; i++){
        cin >> amount[i];
    }
    string s;
    int user , type , value;
    for(int i = 0 ; i< A ; i++){
        cin >> s;
        if(s == "B"){
            cin >> user >> type >> value;
            m[type][user] = value;
        }else{
            cin >> user >> type;
            m[type].erase(user);
        }
    }
    for(auto it = m.begin() ; it != m.end() ; it++){
        priority_queue <pair<int , int> > pq;
        for(auto it2 = it->second.begin() ; it2 != it->second.end() ; it2++){
            auto p = make_pair(it2->second , it2->first);
            pq.push(p);
        }
        for(int i = 0 ; i < amount[it->first] ; i++){
            if(!pq.empty()){
                auto a = pq.top();
            pq.pop();
            usergot[a.second].push_back(it->first);
            }
        }
    }
    for(int j = 1 ; j< M+1 ; j++){
        if(usergot[j].empty()){
            cout << "NONE\n";
        }else{
            sort(usergot[j].begin() , usergot[j].end());
            for(int i = 0 ; i < usergot[j].size() ; i++){
                cout << usergot[j][i] << " ";
            }
            cout << "\n";
        }
    }

}
// 2 3 4
// 1 1
// B 1 1 10 B 2 1 100 B 1 2 99 B 2 2 100

// 2 3 5
// 1 1
// B 1 1 10 B 2 1 100 B 1 2 99 B 2 2 100 B 2 2 98

// 2 3 2
// 1 1
// B 1 1 100 B 2 1 100

// 2 3 5
// 1 1
// B 1 1 10 B 2 1 100 W 1 1
// B 2 2 100 B 2 2 98

// 2 3 3
// 2 1
// B 1 1 10 B 2 1 100 B 2 2 1