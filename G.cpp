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

vector <vector <vector <pair<int, int>>>> adj;
vector <vector <int>> deg;
string ans;

void go(int i, int j)
{
    while(!adj[i][j].empty()) {
        auto p = adj[i][j].back();
        adj[i][j].pop_back();
        go(p.X, p.Y);
    }
    ans.push_back(char('0'+j));
}

void burn()
{
    int n; cin >> n;
    adj.clear(), deg.clear();
    adj.assign(150, vector <vector <pair<int, int>>> (150));
    deg.assign(150, vector <int> (150, 0));
    pair<int, int> st = {-1, -1};
    for (int i = 0; i < n-2; i++) {
        string s; cin >> s;
        st = {s[0]-'0', s[1]-'0'};
        deg[s[0]-'0'][s[1]-'0']++;
        deg[s[1]-'0'][s[2]-'0']--;
        adj[s[0]-'0'][s[1]-'0'].emplace_back(s[1]-'0', s[2]-'0');
    }
    int in = 0, out = 0;
    for (int i = 0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            if (deg[i][j] == 1) {
                if (out++) return void (cout << "NO");
                st = {i, j};
            }
            else if (deg[i][j] == -1) {
                if (in++) return void (cout << "NO");
            }
            else if (deg[i][j]) return void (cout << "NO");
        }
    }
    if (out != in) return void (cout << "NO");
    go(st.X, st.Y);
    if (ans.size() != n-1) return void (cout << "NO");
    cout << "YES\n";
    cout << char(st.X+'0');
    reverse(ans.begin(), ans.end());
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