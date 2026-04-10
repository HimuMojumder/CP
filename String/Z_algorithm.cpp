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


vector<int>zalgo(string &s){
    int n=s.size();
    vector<int>z(n,0);
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<r){
            z[i]=z[i-l];
            //z[i] jodi r ar thek beshil character ney 
            //tahole
            if(i+z[i]>r){
                z[i]=r-i;
            }
        }
        // jodi range r ar pore o kicu match thke 

        while(i+z[i]<n and s[z[i]]==s[i+z[i]])z[i]++;

        // jodi while loop chole tahole l ,r update korte hobe
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
      
    }
      return z;
}
void solve()
{
    string s,t;
    cin>>s>>t;
    int n=t.size();
    string tm=t+"$"+s;
    vector<int>z=zalgo(tm);
    int ans=0;
    // chaile kon kon possition a milce index o neya jabe

    for(int i=0;i<(int)tm.size();i++){
        if(z[i]==n)ans++;
    }
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
