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
    int n; cin >> n;
    set <pair<int, int>> st;
    st.insert({-1, 0}), st.insert({-1, 1}), st.insert({-1, 2});
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        st.insert({i, a});
    }
    auto it = st.begin();
    while(true) {
        while(next(it) != st.end() && !~it->X) it++;
        if (next(it) == st.end()) break;
        if (it->Y == next(it)->Y) {
            st.erase(next(it));
            it = prev(it);
            st.erase(next(it));
            it = prev(it);
        }
        it++;
    }
    for (int i = 0; i < 3; i++) st.erase(st.begin());
    cout << st.size() << '\n';
    for (auto &i : st) cout << i.Y << ' ';
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