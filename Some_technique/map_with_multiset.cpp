//find 
map<int,int>mp;
  map<int,set<int>>mp2;
  while(j<n){
       mp2[mp[v[j]]].erase(v[j]);
       if(mp2[mp[v[j]]].empty())mp2.erase(mp[v[j]]);
       mp[v[j]]++;
       mp2[mp[v[j]]].insert(v[j]);
       if(j-i+1==k){
            cout<<*mp2.rbegin()->second.begin()<<" \n"[i==n-1];
            mp2[mp[v[i]]].erase(v[i]);
            if(mp2[mp[v[i]]].empty())mp2.erase(mp[v[i]]);
            mp[v[i]]--;
            if(mp[v[i]]==0)mp.erase(v[i]);
            else {
                mp2[mp[v[i]]].insert(v[i]);
            }
          i++;
       } 
       j++;
  }
