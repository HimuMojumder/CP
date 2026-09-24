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
const int IN=1e18;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>g(n+1,vector<int>(n+1,IN));
    for(int i=0;i<=n;i++)g[i][i]=0;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x][y]=min(g[x][y],wt);
        g[y][x]=min(g[y][x],wt);
    }
 
    for(int p=1;p<=n;p++){
         for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][p]+g[p][j]);
            }
         }
    }
 
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        if(g[x][y]==IN)g[x][y]=-1;
        cout<<g[x][y]<<endl;
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
