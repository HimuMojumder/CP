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

int bigmode(int a,int b){
    if(b==0)return 1;
    if(b%2){
        return (a%mod*bigmode(a,b-1)%mod)%mod;
    }else{
      int tem=bigmode(a,b/2)%mod;
    return (tem*tem)%mod;
    }
   
}
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
         int a,b;
         cin>>a>>b;
         v.pb({a,b});
    }
    int numofdivisor=1;
    for(int i=0;i<n;i++){
         numofdivisor=(numofdivisor*(v[i].second+1))%mod;
    }
    int sumofdivisor=1;
    for(int i=0;i<n;i++){
        int tm=(bigmode(v[i].first,v[i].second+1)-1)%mod;
        int ans=bigmode(v[i].first-1,mod-2);
        ans=(tm*ans)%mod;
        sumofdivisor=(sumofdivisor*ans)%mod;
    }
   // cout<<numofdivisor<<" "<<sumofdivisor<<endl;
   //int productofdivisor=1;
   int num1=1;
   bool is=true;
   for(int i=0;i<n;i++){
       if(v[i].second%2 and is){
           num1=(num1*(v[i].second+1)/2)%(mod-1);
           is=false;
       }else{
            num1=(num1*(v[i].second+1))%(mod-1);
       }
   }
   if(is){
       for(int i=0;i<n;i++){
          v[i].second/=2;
       }
   }
   int ornum=1;
   for(int i=0;i<n;i++){
         int tm=bigmode(v[i].first,v[i].second);
         ornum=(ornum*tm)%mod;
   }
   int productofsum=bigmode(ornum,num1);
   cout<<numofdivisor<<" "<<sumofdivisor<<" "<<productofsum<<endl;

    
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
