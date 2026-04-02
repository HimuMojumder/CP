/*

cut into squre  how many step

*/
int dp[501][501];
int fun(int x,int k){
    int ans=1e9;
    if(x==k)return 0; 
    if(dp[x][k]!=-1)return dp[x][k];
    for(int i=1;i<=x/2;i++){
        int le=i;
        int ri=x-i;
        int tem= fun(le,k)+fun(ri,k)+1;
        ans=min(ans,tem);
    }
    for(int i=1;i<=k/2;i++){
        int le=i;
        int ri=k-i;
        int tem=1+fun(x,le)+fun(x,ri);
        ans=min(ans,tem);
    }
    dp[x][k]=ans;
    dp[k][x]=ans;
    return ans;
 
}
void solve()
{
    cin>>n>>k;
    memset(dp,-1,sizeof dp);
    cout<<fun(n,k)<<endl;
 
    
 
