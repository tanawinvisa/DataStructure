#include <iostream>
#include <vector>
using namespace std;
#include <set>
#include <map>
#include <queue>

int main(){
    priority_queue<int ,vector<int> , greater<int> > pq;
    pq.push(3);
    pq.push(2);
    pq.push(4);
    int a = 0;
    while(! pq.empty()){
        a = pq.top();
        pq.pop();
        cout << a;
    }
    less<int> x;
    queue<int> q[10];
    set<int> s[10];
    vector<int> v[10];
    cout << "\n sjifhlsjdfhlaskjdfhlajshdf";
    cout << 0% 0 ;
    cout << endl;
    cout << x(1,2);
    cout << endl;
    cout << x(2,1);
    cout << endl;
    cout << x(2,2);
    priority_queue<string> pqs;
    pqs.push("a");
    pqs.push("b");
    while(! pqs.empty()){
        cout << pqs.top();
                pqs.pop();
    }
    
}