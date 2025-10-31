//  "Jai Shri Ram"
// author : himu_mojumder
// "Do more of what you enjoy most."

#include <bits/stdc++.h>
using namespace std;
#define upar(value) upper_bound(v.begin(), v.end(), value) - v.begin();
#define lower(value) lower_bound(v.begin(), v.end(), value) - v.begin();
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define endl "\n"
#define gcd __gcd
#define pb push_back
#define ll long long
#define int ll
#define srt(v) sort(v.begin(), v.end());
#define rsrt(v) sort(v.rbegin(), v.rend());
#define rev(v) reverse(v.begin(), v.end());
#define test   \
    int tt;    \
    cin >> tt; \
    while (tt--)
ll BinarySarch(vector<int> &v, ll target)
{
    ll left = 0, right = v.size() - 1;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)
        {
            left = mid + 1;
        }
        else if (v[mid] > target)
        {
            right = mid - 1;
        }
    }
    return -1;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    srt(v)
            cout
        << BinarySarch(v, k) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // test
    solve();
    return 0;
}