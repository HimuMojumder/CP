//  "Jai Shri Ram"
//  author : himu_mojumder
//  "Do more of what you enjoy most."

/*
if a number can be write with prime factorization like
p1^(x) *p2^(y)* p^(z)
p -> means prime number 
then number of divisors =(x+1)*(y+1)*(z+1);

*/

/*
prime factorization theke sum of devisors
if a number can be write with prime factorization like
p1^(x) *p2^(y)* p^(z)
p -> means prime number 
then sum of devisors= (1+p1^(1)+p1^(2)---+p1^(x)  ) * (1+p2^(1)+p2^(2)---+p2^(y)  ) * (1+p3^(1)+p3^(2)---+p3^(x)  )

(1+p1^(1)+p1^(2)---+p1^(x))    == (p1^(x+1) -1 )/(p-1);
 jodi 
   divisor^2 ar jogpol bear korte hoi
   tahole oporer equation ta arokom hobe
     ans=(1+ p1^2 +p1^4 ..p1^x)*(1+ p2^2 +p2^4 ..p2^x)---

*/

/*
 geometir Series formula

   S =  (a(r^n  -1))  / (r-1)
  here 
   a=first trem
   r=common ration 
   n=number of trem
   
*/




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


