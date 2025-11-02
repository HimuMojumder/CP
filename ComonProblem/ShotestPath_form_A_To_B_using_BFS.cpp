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
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int cost[1001][1001];
int vis[1001][1001];
int direction[1001][1001];
int xA,yA,xB,yB;
string ans="";
void path(int x,int y){
    if(x==xA and y==yA)return ;
    if(direction[x][y]==0){
        ans+='D';
       path(x-1,y);
   
    }
   else if(direction[x][y]==1){
        ans+='U';
         path(x+1,y);
   
    }
  else  if(direction[x][y]==2){
        ans+='R';
        path(x,y-1);

    }
   else if(direction[x][y]==3){
        ans+='L';
       path(x,y+1);
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cin>>v[i][j];
           if(v[i][j]=='A'){
            xA=i;
            yA=j;
           }
            if(v[i][j]=='B'){
            xB=i;
            yB=j;
        }
    }
}
queue<pair<int,int>>q;
q.push({xA,yA});
vis[xA][yA]=1;
cost[xA][yA]=0;
while(!q.empty()){
    auto tem=q.front();
    int x=tem.first;
    int y=tem.second;
    q.pop();
    for(int i=0;i<4;i++){
        int x_=x+dx[i];
        int y_=y+dy[i];
        if(x_<0||x_>=n ||y_<0 ||y_>=m)continue;
        if(vis[x_][y_]==1 || v[x_][y_]=='#')continue;
        
        vis[x_][y_]=1;
        cost[x_][y_]=cost[x][y]+1;
        direction[x_][y_]=i;
        q.push({x_,y_});
    }
}
if(vis[xB][yB]==0)no
else {
    yes
    path(xB,yB);
    rev(ans);
    cout<<cost[xB][yB]<<endl;
    cout<<ans<<endl;
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