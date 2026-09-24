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
int n,m;
const int N=1e3+55;
vector<string>s(N);
int vis[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int level[N][N];
 pair<int,int>A,B;
void bfs(int x,int y,int  ty){
    vis[x][y]=ty;
    queue<pair<int,int>>q;
    q.push({x,y});
    level[x][y]=0;
    while(!q.empty()){
         auto it=q.front();
         q.pop();
         int x=it.first;
         int y=it.second;
         for(int i=0;i<4;i++){
             int x_=x+dx[i];
             int y_=y+dy[i];
             if(x_<0 ||x_>=n ||y_<0||y_>=m || s[x_][y_]=='#'||vis[x_][y_])continue;
             level[x_][y_]=level[x][y]+1;
             vis[x_][y_]=i+1;
             q.push({x_,y_});
         }
    }
  
    if(!vis[B.first][B.second])no
    else{
        string ans;
        int crx=B.first;
        int cry=B.second;
        while(crx!=A.first || cry!=A.second){
            if(vis[crx][cry]==1){
                ans+='D';
                crx--;
            }else if(vis[crx][cry]==2){
                    ans+='U';
                    crx++;
            }else if(vis[crx][cry]==3){
                ans+='R';
                cry--;
            }else{
                 ans+='L';
                 cry++;
            }
        }
        rev(ans);
        yes
        cout<<level[B.first][B.second]<<endl;
        cout<<ans<<endl;
    }
 
    
}
void solve()
{
    memset(vis,0,sizeof(vis));
   // int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
         cin>>s[i];
    }
   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='A'){
                A.first=i;
                A.second=j;
            }
             if(s[i][j]=='B'){
                B.first=i;
                B.second=j;
            }
        }
    }
    bfs(A.first,A.second,-1);
 
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
