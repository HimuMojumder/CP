//  "Jai Shri Ram"
//  author : himu_mojumder
//  "Do more of what you enjoy most."

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
    // je vave cai shebabe return korbo
}

// ------------------ Algorithm Macros ------------------
#define lcm(x, y) y * x / gcd(x, y)

// ------------------ Testcase Macro ------------------
#define test int tt; cin >> tt; while (tt--)

// ------------------ Solve Function ------------------
/*
updata a range and ask a single element
in segment tree lagy

*/


const int mx=2e5+123;
int prop[mx*3];
int vis[mx*3];
int a[mx];
void inti(int id,int b,int e){
    if(b==e){
        prop[id]=a[b];
        return ;
    }
    int mid=(b+e)/2;
    inti(id*2,b,mid);
    inti(id*2+1,mid+1,e);
}
void update(int id,int b,int e,int i,int j,int value){
    if(b>j || e<i)return ;
    if(b>=i and e<=j){
       prop[id]+=value;
       vis[id]=1;
       return ;
    }
    int mid=(b+e)/2;
    update(id*2,b,mid,i,j,value);
    update(id*2+1,mid+1,e,i,j,value);
}
void shift(int id){
    prop[id*2]+=prop[id];
    prop[id*2+1]+=prop[id];
    vis[id*2]=vis[id*2+1]=1;
    prop[id]=vis[id]=0;
}
int ask(int id,int b,int e,int i){
      if(i<b||i>e)return 0;
      if(b==i and e==i){
         return prop[id];
      }
      int mid=(b+e)/2;
      if(vis[id]){
        shift(id);
      }
      int left=ask(id*2,b,mid,i);
      int right=ask(id*2+1,mid+1,e,i);
      return left+right;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    inti(1,1,n);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int a,b,u;
            cin>>a>>b>>u;
            update(1,1,n,a,b,u);
        }else{
            int k;
            cin>>k;
            int ans=ask(1,1,n,k);
            cout<<ans<<endl;
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