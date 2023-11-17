#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    cout<<std::fixed<<std::setprecision(2);
    int N ;
    cin >> N;
    map<string , vector< int > > avg_subject , avg_teacher;
    string sub , teacher;
    int score;
    for(int i = 0; i < N ; i++){
        cin >> sub >> teacher >> score;
        if(avg_subject.find(sub) != avg_subject.end()){
            (avg_subject[sub]).push_back(score);
        }else{
            vector<int> v;
            v.push_back(score);
            avg_subject[sub] = v;
        }
        if(avg_teacher.find(teacher) != avg_teacher.end()){
            (avg_teacher[teacher]).push_back(score);
        }else{
            vector<int> v;
            v.push_back(score);
            avg_teacher[teacher] = v;
        }

    }
    for(auto it = avg_subject.begin() ; it != avg_subject.end() ; it++){
        int sum = 0;
        for( auto &x : it->second){
            sum += x;
        }
        cout << it->first << " " << (sum+0.0)/(it->second.size()) << "\n";
    }
    for(auto it = avg_teacher.begin() ; it != avg_teacher.end() ; it++){
        int sum = 0;
        for( auto &x : it->second){
            sum += x;
        }
        cout << it->first << " " << (sum+0.0)/(it->second.size()) << "\n";
    }
}