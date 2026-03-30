/*
Jai Shree Ram
 
  _    _   _____   __  __   _    _ 
 | |  | | |_   _| |  \/  | | |  | |
 | |__| |   | |   | \  / | | |  | |
 |  __  |   | |   | |\/| | | |  | |
 | |  | |  _| |_  | |  | | | |__| |
 |_|  |_| |_____| |_|  |_|  \____/ 
 
*/
 
#include <bits/stdc++.h>
using namespace std;
 
 
// ------------------ Solve Function ------------------
int v[200200];
struct  node
{
    int add;
    int set;
    int sum;
    node(){
         add=0;
         set=0;
         sum=0;
    }
};
node marge(node a,node b){
      node ans;
      ans.sum=a.sum+b.sum;
      return ans;
}
node t[4*200200];
void push(int id,int l,int r){
    if(t[id].set!=0){
        t[id].sum=t[id].set*(r-l+1);
        if(l!=r){
            t[id*2].set=t[id].set;
            t[id*2+1].set=t[id].set;
            t[id*2].add=0;
            t[id*2+1].add=0;
        }
        t[id].set=0;
    }
    if(t[id].add!=0){
        t[id].sum+=(t[id].add*(r-l+1));
        if(r!=l){
            t[id*2].add+=t[id].add;
            t[id*2+1].add+=t[id].add;
        }
        t[id].add=0;
    }
}
void build(int id,int l,int r){
    if(l==r){
        t[id].sum=v[l];
        t[id].set=0;
        t[id].add=0;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=marge(t[id*2],t[id*2+1]);
}
void update_add(int id,int l,int r,int a,int b,int val){
    push(id,l,r);
    if(a>r||b<l)return;
    if(a<=l and r<=b){
        t[id].add+=val;
        push(id,l,r);
        return;
    }
    int mid=(l+r)/2;
    update_add(id*2,l,mid,a,b,val);
    update_add(id*2+1,mid+1,r,a,b,val);
    t[id]=marge(t[id*2],t[id*2+1]);
}
void update_set(int id,int l,int r,int a,int b,int val){
     push(id,l,r);
    if(a>r||b<l)return;
    if(a<=l and r<=b){
        t[id].set=val;
        t[id].add=0;
        push(id,l,r);
        return;
    }
    int mid=(l+r)/2;
    update_set(id*2,l,mid,a,b,val);
    update_set(id*2+1,mid+1,r,a,b,val);
    t[id]=marge(t[id*2],t[id*2+1]);
}
node query(int id,int l,int r,int a,int b){
     push(id,l,r);
     if(a>r||b<l)return node();
     if(a<=l and b>=r){
        return t[id];
     }
     int mid=(l+r)/2;
     return marge(query(id*2,l,mid,a,b),query(id*2+1,mid+1,r,a,b));
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>v[i];
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int ch,a,b,x;
        cin>>ch;
        if(ch==1){
            cin>>a>>b>>x;
            update_add(1,1,n,a,b,x);
        }else if(ch==2){
            cin>>a>>b>>x;
            update_set(1,1,n,a,b,x);
        }else{
           cin>>a>>b;
           node ans=query(1,1,n,a,b);
           cout<<ans.sum<<endl;
        }
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
