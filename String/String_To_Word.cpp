#include<bits/stdc++.h>
using namespace std;
int main(){
      //tolower
    //     string t=tolower(t);
   //   string  p=toupper(p)
      string s;
    getline(cin,s);
    vector<string>v;
    string word;
    stringstream ss(s);
    while(ss>>word){
        v.push_back(word);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;

}
