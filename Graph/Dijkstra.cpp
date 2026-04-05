3include<bits/stdc++.h>
using name space std;
#difine pb push_back();
#define int long long

const int N=100200;
const int IN = 1e18; 
vector<pair<int,int>>g[N];
 int n,m;


void dijkstra(int source){
    vector<int>dis(N,IN);
    vector<int>vis(N,0);
    set<pair<int,int>>st;
    vector<int>to(N);
    to[source]=-1;
    st.insert({0,source});
    dis[source]=0;
    while(!st.empty()){
         auto node=*st.begin();
         st.erase(st.begin());
         int v=node.second;
         int distancce=node.first;
         if(vis[v]==1)continue;
         vis[v]=1;
         for(auto child:g[v]){
            int child_v=child.first;
            int wt=child.second;
            if(dis[v]+wt<dis[child_v]){
                 to[child_v]=v;
                  dis[child_v]=dis[v]+wt;
                  st.insert({dis[child_v],child_v});
            }
         }

    }

 // printing distance from source to every node

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;


  /// if there here any node form 1 to n 
  // if not print -1;
    if(dis[n]==IN){
        cout<<-1<<endl;
        return;
    }

  /*
  print path form soruce to destination here 1 to n
  */
    int cr=n;
    vector<int>path;
    while(cr!= 1){
        path.pb(cr);
        cr=to[cr];
    }
    path.pb(1);
    rev(path);
    for(int i=0;i<(int)path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;



}
void solve()
{
   
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].pb({y,w});
        g[y].pb({x,w});
    }
    dijkstra(1);
    
}
