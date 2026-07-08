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

#define int long long
int dp[2][11][20][2];
// ------------------ Solve Function ------------------
int dp_func(string &s,int tight,int prev,int idx,int lz){
        if(idx==(int)s.size())return 1;
        if(dp[tight][prev][idx][lz]!=-1)return dp[tight][prev][idx][lz];
        int lb=0;
        int ub=(tight==1)?s[idx]-'0':9;
        int res=0;
        for(int dig=lb;dig<=ub;dig++){
            //in valid case
             if(dig==prev and !lz)continue;
             res+= dp_func(s,tight&(dig==ub),dig,idx+1,lz&(dig==0));

        }
        return dp[tight][prev][idx][lz]= res;


}
int giveme(int a,int b){
    string l=to_string(a-1);
    string r=to_string(b);
    memset(dp,-1,sizeof(dp));
    int right_ans=dp_func(r,1,10,0,1);
      memset(dp,-1,sizeof(dp));
    int left_ans=dp_func(l,1,10,0,1);
    return right_ans-left_ans;
}
void solve()
{
    int a,b;
    cin>>a>>b;
    int ans=giveme(a,b);
    cout<<ans<<endl;
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
