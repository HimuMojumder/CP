#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int bigmode(int a,int b){
    if(b==0)return 1;
    if(b%2){
        return (a%mod+bigmode(a,b-1)%mod)%mod;
    }else{
      int tem=bigmode(a,b/2)%mod;
    return (tem*tem)%mod;
    }
   
}
int main(){
    int a,b;
    cin>>a>>b;
    int tem=bigmode(a,b);
    cout<<tem<<endl;

    return 0;
}