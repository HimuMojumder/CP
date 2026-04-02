/*
only combination use
*/
vector<int>dp(k+1,-1);
   dp[0]=1;
   for(int i=0;i<n;i++){
      for(int j=0;j<=k;j++){
          if(dp[j]==-1)continue;
          if(j+v[i]>k)continue;
        if(dp[j+v[i]]==-1)dp[j+v[i]]=dp[j];
        else dp[j+v[i]]=(dp[j]+dp[j+v[i]])%mod;
      }
   }
   if(dp[k]==-1)dp[k]=0;
   cout<<dp[k]<<endl;

/*
combination with permutaion
*/
    vector<int>v(n);
    //srt(v);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int>dp(k+1,0);
    dp[0]=1;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-v[j]>=0){
                dp[i]=(dp[i]+dp[i-v[j]])%mod;
            }
        }
    }
    cout<<dp[k]<<endl;



