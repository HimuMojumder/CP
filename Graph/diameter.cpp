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
const int N=2*1e5+5;
bool vis[N];
vector<int>gp[N];
int maxdistance=0;
int maxnode=0;
void dfs(int node,int parant,int distance){
       if(distance>maxdistance){
        maxdistance=distance;
        maxnode=node;
       }
      for(auto it:gp[node]){
          if(it==parant)continue;
          dfs(it,node,distance+1);
       }
 
 }
void solve()
 
{
 int n,m;
 cin>>n;
for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        gp[a].pb(b);
        gp[b].pb(a);
}
  dfs(1,0,0);
  int x=maxnode;
  maxnode=0;
  maxdistance=0;
  dfs(x,0,0);
  cout<<maxdistance<<endl;
}
// ------------------ Main Function ------------------
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  //  test
    solve();
    return 0;
}
