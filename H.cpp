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
    int n, k; cin >> n >> k;
    vector <int> dp[20];
    for (auto &i : dp) i.assign(n, -2e9);
    map <int, int> pos;
    vector <pair<int, int>> all;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        all.emplace_back(x, y);
        pos[x] = i;
        dp[0][i] = x+y;
    }
    for (auto &i : all) pos[i.X+k] = max(0, pos[i.X+k]);
    auto it = pos.begin();
    while(next(it) != pos.end()) {
        next(it)->Y = max(next(it)->Y, it->Y);
        it++;
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j+(1<<i)-1 < n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j+(1<<(i-1))]);
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int lim = pos[all[i].X+k];
        if (lim == i) continue;
        int len = 31-__builtin_clz(lim-i);
        int mx = max(dp[len][i+1], dp[len][lim-(1<<len)+1]);
        ans = max(ans, mx+all[i].Y-all[i].X);
    }
    cout << ans;
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