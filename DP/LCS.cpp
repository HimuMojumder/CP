/*
LCS find and print

  */
int n,m;
    cin>>n>>m;
    vector<int>a(n+1),b(m+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
             if(i==0||j==0){
                dp[i][j]=0;
             }
             else if(a[i]==b[j]){
                 dp[i][j]=1+dp[i-1][j-1];
             }else{
                 int tem1=dp[i-1][j];
                 int tem2=dp[i][j-1];
                 dp[i][j]=max(tem1,tem2);
             }
        }
    }
    int i=n,j=m;
    vector<int>tem;
    while(i>0 and j>0){
          if(a[i]==b[j]){
              tem.push_back(a[i]);
              i--;
              j--;
          }else if(dp[i-1][j]>=dp[i][j-1]){
                 i--;
 
          }else{
            j--;
          }
    }
    cout<<dp[n][m]<<endl;
    for(int i=tem.size()-1;i>=0;i--){
          cout<<tem[i]<<" \n"[i==0];
    }
