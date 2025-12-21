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

// if p is a prime number
//a^p%p =a%p
//a^-1 % p=(a^(p-2)) %p
//(a/c)%p =( (a%p)*(bigmode(c,p-2))%p) )%P;

// a^(b^c) calculate
/*
a^b % mod m =(a^(b % phi(mod)) %mod;
    */
int main(){
    int a,b;
    cin>>a>>b;
    int tem=bigmode(a,b);
    cout<<tem<<endl;

    return 0;

}



