//  "Jai Shri Ram"
//  author : himu_mojumder
//  "Do more of what you enjoy most."

#include <bits/stdc++.h>
using namespace std;

#define upar(value) upper_bound(v.begin(), v.end(), value) - v.begin();
#define lower(value) lower_bound(v.begin(), v.end(), value) - v.begin();
#define endl "\n"
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define gcd __gcd
#define pb push_back
#define ll long long
#define int long long

#define lop(i, a, b) for (int i = a; i < b; ++i)
#define rlop(i, a, b) for (int i = a; i >= b; --i)
#define input(v) for (int i = 0; i < n; ++i) cin >> (v)[i];

#define srt(v) sort(v.begin(), v.end());
#define rsrt(v) sort(v.rbegin(), v.rend());
#define rev(v) reverse(v.begin(), v.end());
#define uniq(v) srt(v); v.erase(unique(v.begin(), v.end()), v.end());

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef map<int, int> mii;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    if ((p1.first - p1.second) == (p2.first - p2.second))
        return (p1.first < p2.first);
    return ((p1.first - p1.second) > (p2.first - p2.second));
}

#define lcm(x, y) y * x / gcd(x, y)
#define test int tt; cin >> tt; while (tt--)

const int mx = 100000 + 5;
struct info { int prop, sum; } tree[mx * 4];
int arr[mx];

void build(int node, int b, int e) {
    if (b == e) {
        tree[node].sum = arr[b];
        tree[node].prop = 0;
        return;
    }
    int L = node << 1;
    int R = (node << 1) + 1;
    int mid = (b + e) >> 1;
    build(L, b, mid);
    build(R, mid + 1, e);
    tree[node].sum = tree[L].sum + tree[R].sum;
    tree[node].prop = 0;
}

void update(int node, int b, int e, int i, int j, int x) {
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) {
        tree[node].sum += (e - b + 1) * x;
        tree[node].prop += x;
        return;
    }
    int L = node << 1;
    int R = (node << 1) + 1;
    int mid = (b + e) >> 1;
    update(L, b, mid, i, j, x);
    update(R, mid + 1, e, i, j, x);
    tree[node].sum = tree[L].sum + tree[R].sum + (e - b + 1) * tree[node].prop;
}

int query(int node, int b, int e, int i, int j, int carry = 0) {
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node].sum + carry * (e - b + 1);
    int L = node << 1;
    int R = (node << 1) + 1;
    int mid = (b + e) >> 1;
    int p1 = query(L, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(R, mid + 1, e, i, j, carry + tree[node].prop);
    return p1 + p2;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
