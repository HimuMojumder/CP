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
 
// ---------------------- Macros ----------------------
#define upar(value) upper_bound(v.begin(), v.end(), value) - v.begin();
#define lower(value) lower_bound(v.begin(), v.end(), value) - v.begin();
#define endl "\n"
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define gcd __gcd
#define pb push_back
#define ll long long
#define int long long
 
#define lop(i, a, b) for (int i = a; i < b; ++i)
#define rlop(i, a, b) for (int i = a; i >= b; --i)
 
#define input(v) for (int i = 0; i < n; ++i) cin >> (v)[i];
 
// ------------------ Sorting Macros ------------------
#define srt(v) sort(v.begin(), v.end());
#define rsrt(v) sort(v.rbegin(), v.rend());
#define rev(v) reverse(v.begin(), v.end());
#define uniq(v) srt(v); v.erase(unique(v.begin(), v.end()), v.end());
 
// ------------------ Typedefs ------------------
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef map<int, int> mii;
 
// ------------------ Custom Comparator ------------------
bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    if ((p1.first - p1.second) == (p2.first - p2.second))
        return (p1.first < p2.first);
    return ((p1.first - p1.second) > (p2.first - p2.second));
}
 
// ------------------ Algorithm Macros ------------------
#define lcm(x, y) y * x / gcd(x, y)
 
// ------------------ Testcase Macro ------------------
#define test int tt; cin >> tt; while (tt--)
 
// ------------------ Solve Function ------------------
int v[200200];
struct  node
{
    pii lazy;
    int sum;
    node(){
        sum=0;
        lazy.first=0;
        lazy.second=0;
    }
};
node marge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    return ans;
}
node t[4*200200];
int  calculate(int num, int  a, int d) {
    if(num % 2 == 0) {
        return (num/2) * (2*a + (num-1)*d);
    } else {
        return num * ((2*a + (num-1)*d)/2);
    }
}
void push(int id,int l,int r){
    if(t[id].lazy.first==0 and t[id].lazy.second==0)return;
    t[id].sum+=calculate(r-l+1,t[id].lazy.first,t[id].lazy.second);
    if(l!=r){
        t[id*2].lazy.first+=t[id].lazy.first;
        t[id*2].lazy.second+=t[id].lazy.second;
        int mid=(l+r)/2;
         int nm=mid-l+1;
        t[id*2+1].lazy.first+=(t[id].lazy.first+nm*t[id].lazy.second);
        t[id*2+1].lazy.second+=t[id].lazy.second;
    }
    t[id].lazy={0,0};
}
void build(int id,int l,int r){
    if(l==r){
         t[id].sum=v[l];
         t[id].lazy.first=0;
         t[id].lazy.second=0;
         return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=marge(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int lq,int rq,int a,int d){
    push(id,l,r);
    if(lq>r||rq<l)return;
    if(lq<=l and rq>=r){
        int start = a + (l - lq) * d;
        t[id].lazy={t[id].lazy.first+start,t[id].lazy.second+d};
        push(id,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,lq,rq,a,d);
    update(id*2+1,mid+1,r,lq,rq,a,d);
    t[id]=marge(t[id*2],t[id*2+1]);
}
node query(int id,int l,int r,int a,int b){
    push(id,l,r);
    if(a>r ||b<l)return node();
    if(a<=l and r<=b){
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
       int ch,a,b;
       cin>>ch>>a>>b;
       if(ch==1){
       
          update(1,1,n,a,b,1,1);
       }else{
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
