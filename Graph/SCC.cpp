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
const int N=2e5+55;
int  vis[N];
vector<int>gp[N];
vector<int>revg[N];
int nai[N];
vector<int>ans;
bool is=true;
int to[N];
void dfs(int vertex){
    vis[vertex]=1;
 
    for(int child : gp[vertex]){
         if(vis[child])continue;
       
             dfs(child);
    }
    vis[vertex]=2;
     ans.pb(vertex);
   // nai[vertex]=true;
 
}
 void dfs2(int vertex){
    vis[vertex]=1;
 
    for(int child : revg[vertex]){
        // if(vis[child]==2)continue;
        if(vis[child]){
           continue;
        }
             dfs2(child);
    }
   // vis[vertex]=2;
   //  ans.pb(vertex);
   // nai[vertex]=true;
 
}
void solve()
 
{
 int n,m;
 cin>>n>>m;
 is=true;
for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        gp[a].pb(b);
       // gp[b].pb(a);
}
for(int i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i);
    }
}
rev(ans);

for(int i=1;i<=n;i++){
    vis[i]=0;
      for(auto it:gp[i]){
           revg[it].pb(i);
      }
}
vector<int>tm;
for(int i=0;i<n;i++){
    if(!vis[ans[i]]){
      
          tm.pb(ans[i]);
            dfs2(ans[i]);
    }
}
  
 
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
