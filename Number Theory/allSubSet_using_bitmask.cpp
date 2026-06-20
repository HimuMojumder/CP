
    int n,k;
    cin>>n>>k;
    vector<int>v(k);
    for(int i=0;i<k;i++)cin>>v[i];
    int ans=0;
    for(int mask=0;mask<(1<<k);mask++){
        for(int i=0;i<k;i++){
            if(mask&(1<<i)){
                //here is subset
            }
        }
    }
   cout<<ans<<endl;

