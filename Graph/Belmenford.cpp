//chack the all  constant 


#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,pair<int,int>>>edg;
void belmenford(int source){
    vector<int>dis(n+1,INT_MAX);
    dis[source]=0;
    bool udp=false;
    for(int i=1;i<=n;i++){
        udp=false;
        for(auto it:edg){
          int from=it.first;
          int to=it.second.first;
          int wt=it.second.second;
          if(dis[from] != INT_MAX && dis[to]>dis[from]+wt){
             dis[to]=dis[from]+wt;
             udp=true;
          }

        }
        if(udp==false)break;
    }
    if(udp){
        cout<<"cycle here"<<endl;
    }

    //distance 
    // there can be INF
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" \n"[i==n];
    }

}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edg.push_back({u,{v,w}});
    }
    belmenford(1);
    return 0;
}
