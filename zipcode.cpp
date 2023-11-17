#include <iostream> 
#include <string> 
#include <algorithm>
#include <vector> 
#include <map> 
using namespace std; 
class Letter{
    public:
    string name; 
    string address; 
    string province; 
    string district; 
    int zip; 
    bool operator < (const Letter& other) const {
    //**Begin Insert**
    if( zip !=other.zip){
        return  zip < other.zip;
    }else{
        if(address != other.address){
            return address < other.address;
        }else{
            if(district != other.district){
                return district < other.district;
            }else{
                if(province != other.province){
                    return province < other.province;
                }else{
                    return name < other.name;
                }
            }
            
        }
    }
    //**End Insert** 
    }
};
class ZipInfo{ 
    public:
    int zip;
    string province;    
    string district;
};
void correctZipAndSortLetters(vector<ZipInfo>& zipinfo, vector<Letter>& letters) { 
    //**Begin Insert**
    map<pair<string,string> , int> mp;
    for(int i = 0 ; i < zipinfo.size() ; i++){
        pair<string , string> p = make_pair(zipinfo[i].province , zipinfo[i].district);
        mp[p] = zipinfo[i].zip;
    }
    for(int i = 0 ; i < letters.size() ; i++){
        pair<string , string> p = make_pair(letters[i].province,letters[i].district);
        letters[i].zip = mp[p];
    }
    sort(letters.begin() , letters.end());


//**End Insert** 
}
int main() { 
    int nzip;
    cin>>nzip; 
    vector<ZipInfo> zipinfo; 
    for (int i = 0; i < nzip; i++) {
        ZipInfo z; 
        cin>>z.zip>>z.district>>z.province; 
        zipinfo.push_back(z);
    }
    int n;
    cin>>n;
    vector<Letter> letters; 
    for (int i = 0; i < n; i++) {
        Letter l; 
        cin>>l.name>>l.address>>l.district>>l.province>>l.zip; 
        letters.push_back(l);
    }
    correctZipAndSortLetters(zipinfo, letters); 
    for (auto& l:letters) {
    cout<<l.name<<" "<<l.address<<" "<<l.district<<" "<<l.province<<" "<<l.zip<<endl; }
}

