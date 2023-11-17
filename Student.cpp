#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Student{
    public: 
        string getName(){
            return this->Fname +" " + this->Lname;

    }

    void setName(string Fname , string Lname , int gpx){
            this->Fname = Fname;
            this->Lname = Lname;
            this->gpx = gpx;
        }
    
    bool operator<( const Student & other)const{
        if(this->gpx == other.gpx){
            return this->Fname < other.Fname;
        }
        return this->gpx < other.gpx;
    }


    private:
        string Fname;
        string Lname;
        int gpx;

};

string operator*(string & left , const int & right){
    string result = "";
    for(int i = 0 ; i < right ; i++){
        result += left;
    }
    return result;
}

int ct(queue<int> q ,vector<int> v){
        int time = 0;
        int n = v.size();
        while(true){
            for(int i = 0 ; i < n ; i++){
                if(q.empty()) return time;
                if(time % v[i] == 0) q.pop();
            }
            if(q.empty()) return time;
            time ++;
        }
        return time;
    }


int main(){

    
    Student s, s2;
    s.setName("win", "visa" , 3);
    s2.setName("mee","si", 3);
 
    cout<< s.getName() << endl;

    string a = "1aaa";
    cout << a * 3 ;

    priority_queue<Student> pq;
    pq.push(s);
    pq.push(s2);
    while(!pq.empty()){
        
        Student h = pq.top();
        cout << h.getName();
        pq.pop();
    }

    vector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    vector<int> v2(4);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v2[3] = 4;

    cout <<( v1 > v2) << endl;

    set<int> se;
    set<int> se1;
    se.insert(1);
    se1.insert(1);
    se1.insert(2);
    cout << (se < se1) ;
    
    map<int , int> m ,m2;
    m[1] = 1;
    m[2] = 1;
    m2[2] = 0;
    cout << (m < m2) ;

    queue<int> q ;
    q.push(1);
        q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(1);
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    cout << ct(q,v);
}
