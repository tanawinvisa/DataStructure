#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m,  current_sum = 0;
    cin >> n >> m;
    vector<int> p(m), money;
    queue<int> A;
    queue<int> B;
    for (int i = 0; i < m; i++) cin >> p[i];
    while (n--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int a, b;
            cin >> a >> b;
            if (a == 1) {
                A.push(b);
            } else {
                B.push(b);
            }

        } else {
            if (A.empty()) {
                current_sum += B.front();
                B.pop();
            } else if (B.empty()) {
                current_sum += A.front();
                A.pop();
            } else {
                if (A.front() > B.front()) {
                    current_sum += B.front();
                    B.pop();
                } else {
                    current_sum += A.front();
                    A.pop();
                }
            }
            money.push_back(current_sum);
            cout << endl;
            cout << "sum";
            cout << current_sum <<endl;

        }
        
    }

    for (int x : p) {
        if (x > *(money.end() - 1)) {
            cout << -1 << " ";
        } else {
            auto it = lower_bound(money.begin(), money.end(), x);
            cout << it - money.begin() + 1 << " ";
        }
    }


}

