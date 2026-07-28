/*
Jai Shree Ram
*/

#include<bits/stdc++.h>
#define int       long long

using namespace std;
const int N=1e6+5;
bitset<N>p;
vector<int>prime;

void seive(){
    p[1]=0;
    for(int i=2;i*i<N;i++){
        if(!p[i]){
            for(int j=i*i;j<N;j+=i){
                p[j]=1;
            }
        }
    }
    for(int i=2;i<N;i++){
        if(!p[i])prime.push_back(i);
    }

}
void solve(int tc){
         int a,b;
         cin>>a>>b;
         int num=b-a+1;
      //creat dummy vector for a to b ;
       // hare index  of a is 0;  
         vector<bool>daprime(num+5,1);
         //handle for  case 1
         // this is an ege case
         if(a==1)daprime[0]=0;
         for(auto pnum:prime){
             if(pnum*pnum>b)break;
             //find frist number which is mulple of this prime
             int st=(a/pnum)*pnum;
             if(st<a)st+=pnum;
            //finde starting index
             st=max(st,pnum*pnum);
            // just normal seive 
             for(int j=st;j<=b;j+=pnum){
                 daprime[j-a]=0;
             }
         }
         vector<int>segmentprime;
         //dummay vector ar index gula te jai chack kortece
         for(int i=0;i<num;i++){
            if(daprime[i]){
               segmentprime.push_back(i+a);
            }
         }
         //print all prime range a to b
         for(auto it:segmentprime){
              cout<<it<<endl;
         }

}


int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    //frist generate all the prime number upto 1e6 becase the range
    //can be r =1e12
    seive();
   cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;
}
