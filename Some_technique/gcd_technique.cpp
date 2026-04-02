/*
find gcd pair or triplate

*/
  int n;
    cin>>n;
    vector<int>v(1e6+55,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v[x]++;
    }
    for(int i=1;i<=1e6;i++){
          for(int j=i*2;j<=1e6;j+=i){
              v[i]+=v[j];
          }
          v[i]=(v[i]*(v[i]-1))/2;
    }
    for(int i=1e6;i>=1;i--){
         for(int j=i*2;j<=1e6;j+=i){
             v[i]-=v[j];
         }
    }
    cout<<v[1]<<endl;
