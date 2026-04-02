/*
divide into part

*/

int n,k;
    cin>>n>>k;
    int  x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<int>v(n+1);
    v[1]=x;
    for(int i=2;i<=n;i++){
        int tm=(a*v[i-1]+b)%c;
        v[i]=tm;
    }
    vector<int>suf(n+2);
    vector<int>pre(n+1);
    for(int i=1;i<=n;i++){
        if(i%k==1 || k==1)pre[i]=v[i];
        else pre[i]=v[i]|pre[i-1];
    }
    for(int i=n;i>=1;i--){
         if(i%k==0 ||k==1){
              suf[i]=v[i];
         }else suf[i]=v[i]|suf[i+1];
    }
    int ans=0;
    for(int i=k;i<=n;i++){
          int tm=pre[i]|suf[i-k+1];
          ans^=tm;
    }
