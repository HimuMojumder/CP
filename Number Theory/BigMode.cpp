#include<bits/stdc++.h>
using namespace std;
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

int ncr(int n,int r){
    int tem=(fact[n]*bigmode(fact[r],mod-2))%mod;
     tem=(tem*bigmode(fact[n-r],mod-2))%mod;
     return tem;
}

// if p is a prime number
//a^p%p =a%p
//a^-1 % p=(a^(p-2)) %p
//(a/c)%p =( (a%p)*(bigmode(c,p-2))%p) )%P;

// a^(b^c) calculate
/*
a^b % mod m =(a^(b % phi(mod)) %mod;
    */


/*
n children m apple dristribut them how many away
  (m+n-1)C (n-1)

  
*/
int main(){
    int a,b;
    cin>>a>>b;
    int tem=bigmode(a,b);
    cout<<tem<<endl;

    return 0;

}



/*
when a,b and mode upto 1e18 then
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll mul(ll a, ll b, ll mod) { // a * b % mod
  return __int128(a) * b % mod;
}

ll power(ll a, ll b, ll mod) { // a^b % mod
  ll ans = 1 % mod;
  while (b) {
    if (b & 1) ans = mul(ans, a, mod);
    a = mul(a, a, mod);
    b >>= 1;
  }
  return ans;
}

ll inverse(ll a, ll mod) { // (1 / a) % mod
  return power(a, mod - 2, mod);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll a, b, mod; cin >> a >> b >> mod;
  cout << power(a, b, mod) << '\n';
  cout << mul(a, b, mod) << '\n';
  cout << mul(a, inverse(b, mod), mod) << '\n';
  return 0;
}




