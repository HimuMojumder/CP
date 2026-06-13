#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long 
const int N=100200;
const int IN=1e18;
vector<pair<int,int>>g[N];
int n,m;
void dijkstra(int source){
    vector<int>dis(N,IN);
    vector<int>vis(N,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>to(N);
    to[source]=-1;
    dis[source]=0;
    pq.push({0,source});
    while (!pq.empty())
    {
      auto node=pq.top();
      pq.pop();
      int v=node.second;
      int distance=node.first;
      if(vis[v]==1)continue;
      vis[v]=1;
      for(auto child :g[v]){
        int child_v=child.first;
        int wt=child.second;
        if(dis[v]+wt<dis[child_v]){
            to[child_v]=v;
            dis[child_v]=dis[v]+wt;
            pq.push({dis[child_v],child_v});
        }
      }
    }
    
    //printing distance from source to every node
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" \n"[i==n];
    }

    // print path from source(1) to destination (n)
    if(dis[n]==IN){
        cout<<-1<<endl;
        return;
    }


    int cr=n;
    vector<int>path;

    while(cr!=1){
         path.pb(cr);
         cr=to[cr];
    }
    path.pb(1);
    reverse(path.begin(),path.end());
    for(int i=0;i<(int)path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        //for undirected graph
        g[y].push_back({x,w});
    }
    dijkstra(1);
}

int32_t main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     solve();
     return 0;
}
