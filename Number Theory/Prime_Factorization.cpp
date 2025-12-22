#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
// find  prime factorization of single number n

// signed main (){
//     int n;
//     cin>>n;
//     for(int i=2;i*i<=n;i++){
//         if(n%i!=0)continue;
//          int x=0;
//          while(n%i==0){
//             n/=i;
//             x++;
//          }
//          cout<<i<<" "<<x<<endl;
//     }
//     if(n>1)cout<<n<<" "<<1<<endl;

// }


/*
shodu prime gula bebohar kore prime factorization 
seive bebohar kore
  spf-> smallest prime factor
*/

//const int N=1e6+5;

bool isprime[N];
vector<int>ans;
int spf[N];

// akhane ans vector mane prime gular vector

void seive(){
    for(int i=2;i<N;i++)isprime[i]=true;
    for(int i=2;i<N;i++)spf[i]=i;
    

   //sqrt optimization
        
    for(int i=2;i*i<=N;i++){
        if(isprime[i])
        for(int j=i*i;j<N;j+=i){
            if(spf[j]==j)spf[j]=i;
            isprime[j]=false;
        }
    }

    ans.push_back(2);
    for(int i=3;i<N;i+=2){
        if(isprime[i])ans.push_back(i);
    }
}
 
signed main (){
    seive();
//    int n;
//    cin>>n;
//    for(auto it:ans){
//         if(it*it>n)break;
//         if(n%it>0)continue;
//         int x=0;
//         while(n%it==0){
//             n/=it;
//             x++;
//         }
//         cout<<it<<" "<<x<<endl;
//    }
//    if(n>1)cout<<n<<" "<<1<<endl;

// //1 theke 100 porjonto shobgula shogkhar spf

//    for(int i=1;i<=100;i++){
//      cout<<i<<" "<<spf[i]<<endl;
//    }
   

    //spf diya prime factorization
      int n;
      cin>>n;
      while(n>1){
        int x=n;
        int cnt=0;
        while(n%spf[x]){
            n/=spf[x];
            cnt++;
        }
        cout<<spf[x]<<" "<<cnt<<endl;
      }

}