#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
vector<int>g[N];
int vis[N]; 
void dfs (int vartex){
     vis[vartex]=1;
     for(int child:g[vartex]){
        if(vis[child]==0){
            dfs(child);
        }
     }
}

int main(){
   int n,m;
   cin>>n>>m;
   int a,b;
   while(m--){
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }
   //
   dfs(1);

}