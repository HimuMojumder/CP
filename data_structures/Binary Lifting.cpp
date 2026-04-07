const int N=100200;
int v[N];
const int mx=25;
int u[N][mx];
int n,q;
void solve()
{
      cin>>n>>q;
      vector<int>next(n+1);
      deque<int>dq;
      for(int i=1;i<=n;i++)cin>>v[i];
      for(int i=n;i>=1;i--){
        
           while(!dq.empty() and v[dq.back()]<=v[i])dq.pop_back();
           if(dq.empty())next[i]=n+1;
           else next[i]=dq.back();
           dq.push_back(i);
      }
    //   for(int i=1;i<=n;i++){
    //      cout<<next[i]<<" ";
    //   }
    //   cout<<endl;

    //binary lifting
// ai code ta diya amra pre calculation kori je 
// range a thke koi lap deya jabe

    for(int i=1;i<=n;i++)u[i][0]=next[i];
    for(int i=1;i<mx;i++){
    for(int j=1;j<=n;j++){
        if(u[j][i-1] <= n)
            u[j][i] = u[ u[j][i-1] ][i-1];
        else
            u[j][i] = n+1;
    }
}
   
   for(int i=1;i<=q;i++){
      int a,b;
      cin>>a>>b;
      int cnt=1;
      int cr=a;
      for(int i=mx-1;i>=0;i--){
           if(u[cr][i]<=b ){
              cr=u[cr][i];
              cnt+=(1LL<<i);
           }
      }
      cout<<cnt<<endl;
   }


}

// ------------------ Main Function ------------------
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // test
    solve();
    return 0;
}
