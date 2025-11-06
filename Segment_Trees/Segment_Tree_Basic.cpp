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
update a single element in array
*/
const int mx=2e5+123;
int tree[mx*3],arr[mx];
void init(int id,int b,int e){
    if(b==e){
        tree[id]=arr[b];
        return ;
    }
    int mid=(b+e)/2;
    init(id*2,b,mid);
    init(id*2+1,mid+1,e);
    tree[id]=tree[id*2]+tree[id*2+1];

}
void update(int id,int b,int e,int i,int  value){
    if(e<i || b>i)return ;
     if(b==i and e==i){
      tree[id]=value;
      return ;
     }
     int mid=(b+e)/2;
     update(id*2,b,mid,i,value);
     update(id*2+1,mid+1,e,i,value);
     tree[id]=tree[id*2]+tree[id*2+1];

}
int ask(int id,int b,int e,int i,int j){
    if(b>j || e<i)return 0;
    if(b>=i && e<=j)return tree[id];
    int mid=(b+e)/2;
    int left_sum=ask(id*2,b,mid,i,j);
    int right_sum=ask(id*2+1,mid+1,e,i,j);
    return left_sum+right_sum;

}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    init(1,1,n);
    int a,b,c;
    while(m--){
      cin>>a>>b>>c;
      if(a==1){
        update(1,1,n,b,c);
      }else{
        int ans=ask(1,1,n,b,c);
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
