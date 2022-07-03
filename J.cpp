#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define AboTaha_on_da_code ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1}, dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
const ll M = 1e9+7, M2 = 998244353;
const double EPS = 1e-8;

void burn()
{
    ll n, x, m, y;
    cin >> n >> x >> m >> y;
    ll st = 1, en = n;
    pair<ll, ll> ans1;
    while (st <= en) {
        ll mi = (st+en)/2;
        ll inc = min(m, (mi*x-1)/y);
        if (mi+inc <= (n+m)/2) {
            st = mi+1;
            ans1 = {mi+inc, mi};
        }
        else en = mi-1;
    }
    st = 1, en = m;
    pair<ll, ll> ans2;
    while (st <= en) {
        ll mi = (st+en)/2;
        ll inc = min(n, (mi*y-1)/x);
        if (mi+inc <= (n+m)/2) {
            st = mi+1;
            ans2 = {mi+inc, mi};
        }
        else en = mi-1;
    }
    ll fir, sec;
    if (ans1.X == (n + m) / 2) {
        fir = ans1.Y*x;
        ll idx = ans2.Y+1;
        if (idx <= m && (ans1.Y+1 > n || idx+(idx*y-1)/x == (n+m)/2+1)) sec = idx*y;
        else sec = fir+x;
    } else {
        fir = ans2.Y*y;
        ll idx = ans1.Y+1;
        if (idx <= n && (ans2.Y+1 > m || idx+(idx*x-1)/y == (n+m)/2+1)) sec = idx*x;
        else sec = fir+y;
    }
    cout << fixed << setprecision(1) << ((n+m)&1 ? (double)sec : (double)(sec+fir)/2.0);
}

int main()
{
    AboTaha_on_da_code

    // freopen("self.in", "r", stdin);
    /*freopen("output.txt", "w", stdout);*/

    int t = 1; // cin >> t;
    for (int i = 1; i <= t; i++) {
        burn();
        cout << '\n';
    }
    return 0;
}