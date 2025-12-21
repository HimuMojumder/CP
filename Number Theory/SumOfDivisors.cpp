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
#define int  unsigned long long

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
int mod=1e9+7;
// ------------------ Algorithm Macros ------------------
int lcm(int x,int y){
  return  y*x/__gcd(x,y);
}  

// ------------------ Testcase Macro ------------------
#define test int tt; cin >> tt; while (tt--)

// ------------------ Solve Function ------------------

const int INV2 = 500000004; // 2⁻¹ mod MOD
/*
modular arithmatic bebohar kori

*/
int sum(int a,int b){
    int cnt=(b-a+1);
    int ab=a+b;
    int temans=(cnt%mod)*(ab%mod);
    temans%=mod;
    temans *=INV2;
    temans%=mod;
    return temans;

}
void solve()
{

  int n;
  cin>>n;
  int ans=0;
  //1 theke sqrtrote porjontw divisor gula koi
  //bar kore ase tader sum
  for(int i=1;i*i<=n;i++){
     int tem=n/i;
     tem*=i;
     ans+=tem;
     ans%=mod;
  }
  /*
    tar por koi bar kore ase tader sum
    baki gular khetre
  */
  for(int k=1;n/k>k;k++){
    /*
     akhane n/(k+1)+1 theke n/k porjontw shongkha gula k bar divesor hishabe ace;
    
     akta range a theke b porjontw shogkha gular jogpol holo 
     (a+b)*(b-a+1)/2
   (b-a+1)  -> range ar modde kotogula shongkha ace


    */
    int tem=sum(n/(k+1)+1,n/k)*k;
    ans+=tem;
    ans%=mod;
  }
  cout<<ans<<endl;


 // cout<<ans<<endl;
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