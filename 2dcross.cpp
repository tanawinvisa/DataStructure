#include <iostream>
#include <vector>
using namespace std;
void cross_2d(vector<vector<int> > &m ,int r1, int r2, int c1, int c2) { //your code here
    int row_size = m.size();
    int column_size = m[0].size();
    vector<vector<int> > v(row_size - (r2-r1+1));
    int idxi = 0;
    for(int i = 0 ; i < row_size ; i++){
        vector<int> vc(column_size - (c2-c1+1));
        if( i < r1 || i > r2 ){
            int idx = 0;
            for(int j = 0 ; j < column_size ; j++){
                    if( j < c1 || j > c2){
                        vc[idx] = m[i][j]; 
                        idx++;
                    }
            }
            v[idxi] = vc;
            idxi++;
        }
    }
    m = v;
}
int main() { 
    ios_base::sync_with_stdio(false);cin.tie(0); 
    vector<vector<int> > m;
    int r,c,r1,r2,c1,c2;
    cin>> r >> c;
    cin >> r1 >> r2 >> c1 >> c2;
    m.resize(r);
    for (int i =0;i < r;i++) {
        m[i].resize(c);
        for (int j = 0;j < c;j++) {
                cin >> m[i][j];
            }
    }
    cross_2d(m,r1,r2,c1,c2);
    for (int i =0;i < m.size();i++) {
        for (int j = 0;j < m[i].size();j++) { 
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    return 0; 
}