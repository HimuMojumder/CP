/*
main tain left right multiset with lemda function


*/
int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    multiset<int>left,right;
    int ls=0,rs=0;
    auto resize=[&]{
        if(left.size()>right.size()){
              int val=*left.rbegin();
              left.erase(left.find(val));
              right.insert(val);
              ls-=val;
              rs+=val;
 
        }
        if(left.size()+1<right.size()){
              int val=*right.begin();
              rs-=val;
              ls+=val;
              right.erase(right.find(val));
              left.insert(val);
        }
    };
    auto add=[&](int val){
          if(right.empty() || val<*right.begin()){
              left.insert(val);
              ls+=val;
          }else{
              right.insert(val);
              rs+=val;
          }
          resize();
    };
    auto remove=[&](int val){
         if(val>=*right.begin()){
              right.erase(right.find(val));
              rs-=val;
         }else{
            left.erase(left.find(val));
            ls-=val;
         }
         resize();
    };
    auto cost=[&]{
         int mid=*right.begin();
         int tm=(mid*left.size())-ls+rs-(mid*right.size());
         return tm;
    };
    int i=0,j=0;
    while(j<n){
        add(v[j]);
        if(j-i+1==k){
            cout<<cost()<<" \n"[i==n-1];
            remove(v[i]);
            i++;
        }
        j++;
    }
