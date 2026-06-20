#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IN 1e18
int n,m;
vector<pair<int,pair<int,int>>>edg;
void belmenford(){
    vector<int>dis(n+1,0);
   // dis[source]=0;
    bool udp=false;
    int par[n+1];
    int st=-1;
    for(int i=1;i<=n;i++){
        udp=false;
        for(auto it:edg){
          int from=it.first;
          int to=it.second.first;
          int wt=it.second.second;
          if(dis[from] != IN && dis[to]>dis[from]+wt){
             dis[to]=dis[from]+wt;
             udp=true;
             par[to]=from;
             if(i==n)st=to;
          }

        }
        if(udp==false)break;
    }
    if(udp){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)st=par[st];
        vector<int>ans;
        ans.push_back(st);
        int tm=st;
        st=par[st];
        while(st!=tm){
            ans.push_back(st);
            st=par[st];
        }
        ans.push_back(st);
        reverse(ans.begin(),ans.end());
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }

   
}
int32_t main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edg.push_back({u,{v,w}});
    }
    belmenford();
    return 0;
}
