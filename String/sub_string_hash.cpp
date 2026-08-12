/*
Jai Shree Ram
*/

#include<bits/stdc++.h>
#define int       long long
const int INV2 = 500000004;
using namespace std;
const int N=2e5+5;
#define ll long long

const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;

ll mul(ll a, ll b, ll mod) { // a * b % mod
  return  (a) * b % mod;
}

ll pow(ll a, ll b, ll mod) { // a^b % mod
  ll ans = 1 % mod;
  while (b) {
    if (b & 1) ans = mul(ans, a, mod);
    a = mul(a, a, mod);
    b >>= 1;
  }
  return ans;
}


pair<int ,int>power[N],inverse[N];

void  powercal  ( ){ 
    power[0].first = 1;
    power[0].second = 1;

    for(int i = 1; i < N ; i++){
       power[i].first =( power[i-1].first * p1 )%mod1;
       power[i].second =( power[i-1].second * p2 )%mod2;
    }

    int invese_of_p1 =  pow(p1 , mod1-2,mod1);
    int invese_of_p2 =  pow(p2, mod2-2,mod2);

    inverse[0].first = 1;
    inverse[0].second = 1;

    for( int i = 1; i < N ; i++){
         inverse[i].first = (inverse[i-1].first * invese_of_p1 )%mod1;
         inverse[i].second = (inverse[i-1].second * invese_of_p2 )%mod2;
    }

}

pair<int,int>prehash[N];

void build ( string s){
  int len = s.size();
   int cr_hash1 = 0,cr_hash2=0;
   for(int i = 0; i < len ; i++){
        cr_hash1+= (s[i] * power[i].first)%mod1;
        cr_hash1 %= mod1;
        prehash[i].first = cr_hash1;

        cr_hash2+= (s[i] * power[i].second)%mod2;
        cr_hash2 %= mod2;
        prehash[i].second = cr_hash2;
   }
      
}

pair<int,int> get_hash ( int l ,int r){
     pair<int,int> rangehash;
     if(l==0){
        rangehash.first = prehash[r].first;
        rangehash.second = prehash[r].second;
     }else{
         rangehash.first = (prehash[r].first - prehash[l-1].first + mod1) %mod1;
         rangehash.second = (prehash[r].second - prehash[l-1].second + mod2 )% mod2;
     }
     rangehash.first = (rangehash.first * inverse[l].first ) % mod1;
     rangehash.second = (rangehash.second * inverse[l].second ) % mod2;
     return {rangehash.first,rangehash.second};
}
void solve(int tc){
     string s;
     cin>>s;
     build (s);
     if(get_hash(0,1)==get_hash(3 ,4))cout<<1<<endl;
     else cout<<0<<endl;
     
}

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    powercal();
   //  cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;
}
