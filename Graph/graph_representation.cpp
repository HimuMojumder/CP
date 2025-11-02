#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int graph1[N][N];
vector<int>graph2[N];
int main(){
     //adjacency matrix
     int n,m;
    /*
     n->number of node
     m->number of edges
      0(N^2)-  space complexity
     N=1e3 maximum
    */
     cin>>n>>m;
     int a,b;
     while(m--){
        cin>>a>>b;
        //weight deya thake 1 ar jaigai weight divo
        graph1[a][b]=1;
        graph1[b][a]=1;
     }
    

      //adjacency list 
      //space complexity 0(V+E);
      cin>>n>>m;
      while(m--){
        cin>>a>>b;
        /*
        list a amra jodi weight store korte cai amra pair
        rakbo vector ar modde
        vector<pair<int,int>>v[N];
        */
        graph2[a].push_back(b);
        graph2[b].push_back(a);
      }



    return 0;
}