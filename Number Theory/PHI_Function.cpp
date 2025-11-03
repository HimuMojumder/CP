#include<bits/stdc++.h>
using namespace std;
#define ll long long

// portektar jonno indivituraly calculate korteci
// calculate co_Prime


ll phi(ll n){
    ll result =n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            result=result-(result/i);
            while(n%i==0){
                n/=i;
            }
        }
    }
  if(n>1){
     result=result-result/n;
  }
  return result;
}


// 1 theke N porjontw akta vector a store core kore rakte function
/*
complexity o(nloglog(n))
*/
vector<ll>phii(ll n){
   vector<ll>result(n+1);
   for(ll i=0;i<=n;i++){
    result[i]=i;
   }
   for(int i=2;i<=n;i++){
    if(result[i]==i){
        for(int j=i;j<=n;j+=i){
            result[j]=result[j]-result[j]/i;
        }
    }
   }
   return result;
}

//Another away of  storing phi /co_prime
/*
complexity 0(nlogn)
*/
vector<ll>phiii(ll n){
   vector<ll>result(n+1);
   for(ll i=0;i<=n;i++){
    result[i]=i;
   }
   for(int i=1;i<=n;i++){
         for(int j=i+i;j<=n;j+=i){
            result[j]=result[j]-result[i];
        }

   }
   return result;
}

int main(){
    int N=1e5;
       int nuner_of_coprimeOf_N =phi(N);
       //store coprime 1 to N in vector x
        vector<ll> x=phiii(1e5);
         cout<<x[18]<<endl;

    
    return 0;
}