/*
Jai Shree Ram

  _    _   _____   __  __   _    _ 
 | |  | | |_   _| |  \/  | | |  | |
 | |__| |   | |   | \  / | | |  | |
 |  __  |   | |   | |\/| | | |  | |
 | |  | |  _| |_  | |  | | | |__| |
 |_|  |_| |_____| |_|  |_|  \____/ 

*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back



 vector<int>divi;
 void generatedivisor(int cridx,int crdivisor,vector<pair<int,int>>&primefactor){
      if(cridx==primefactor.size()){
          divi.push_back(crdivisor);
          return;
      }
      for(int i=0;i<=primefactor[cridx].first;++i){
           generatedivisor(cridx+1,crdivisor,primefactor);
           crdivisor*=primefactor[cridx].second;
      }
 }
void solve()
{
   int x;
   cin>>x;
   map<int,int>mp;
    vector<pair<int,int>>primefactor;
      int n=x;
      for(int i=2;i*i<=n;i++){
        if(n%i!=0)continue;
         int x=0;
         while(n%i==0){
            n/=i;
            x++;
         }
          primefactor.pb({x,i});
        
    }
    if(n>1) primefactor.pb({1,n});
    
     int crdivi=1; 
     int cridx=0;
     generatedivisor(cridx,crdivi,primefactor);

    //uniq(divi);
    for(auto it:divi){
        cout<<it<<" ";
    }
    cout<<endl;

}

// ------------------ Main Function ------------------
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  //  test
    solve();
    return 0;
}
