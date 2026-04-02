/*
nibo ki nobo na


*/
cin>>n>>k;
    vector<int>dp(k+1,-1);
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int>price(n);
    for(int i=0;i<n;i++)cin>>price[i];
    dp[0]=0;
   for(int i=0;i<n;i++){
      for(int j=k;j>=0;j--){
        if(j+v[i]>k)continue;
        if(dp[j]==-1)continue;
        dp[j+v[i]]=max(dp[j+v[i]],dp[j]+price[i]);
      }
   }
   cout<<*max_element(dp.begin(),dp.end())<<endl;
