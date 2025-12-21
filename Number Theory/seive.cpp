#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e8;
bool isprime[N];
vector<int>ans;
void seive(){
    for(int i=2;i<N;i++)isprime[i]=true;

    for(int i=4;i<N;i+=2)isprime[i]=false;

   //sqrt optimization
        
    for(int i=3;i*i<=N;i+=2){
        if(isprime[i])
        for(int j=i*i;j<N;j+=2*i){
            isprime[j]=false;
        }
    }

    ans.push_back(2);
    for(int i=3;i<N;i+=2){
        if(isprime[i])ans.push_back(i);
    }
}
signed main(){
    seive();
    for(int i=0;i<ans.size();i+=100){
        cout<<ans[i]<<"\n";
    }
}       