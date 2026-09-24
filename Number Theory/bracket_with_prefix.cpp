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
int mod=1e9+7;
 
const int INV2 = 500000004; // 2⁻¹ mod MOD
const int N=2e6+55;
int fact[N];
int bigmode(int a,int b){
    if(b==0)return 1;
    if(b%2){
        return (a%mod*bigmode(a,b-1)%mod)%mod;
    }else{
      int tem=bigmode(a,b/2)%mod;
    return (tem*tem)%mod;
    }
   
}
 
int ncr(int n,int r){
    int tem=(fact[n]*bigmode(fact[r],mod-2))%mod;
     tem=(tem*bigmode(fact[n-r],mod-2))%mod;
     return tem;
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int open=0,close=0;
    for(auto it:s){
        if(it=='(')open++;
        else close++;
        if(close>open){
            cout<<0<<endl;
            return;
        }
    }
    if(n&1 ||open>n/2){
        cout<<0<<endl;
        return;
    }
    int openneed=n/2-open;
    int dif=abs(open-close);
    int total=openneed*2+dif;
 
    int ans1=ncr(total,openneed);
    int ans2=((1+dif)*bigmode(1+dif+openneed,mod-2))%mod;
    int ans=(ans1*ans2)%mod;
    cout<<ans<<endl;
 
}
 
// ------------------ Main Function ------------------
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0]=1;
    for(int i=1;i<N;i++){
        fact[i]=(i*fact[i-1])%mod;
    }
   // test
    solve();
    return 0;
