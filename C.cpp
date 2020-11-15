#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int n, k, ans;
vector<pi> adj[100000];
int is_apt[100000], vst[100000];

int dfs(int u) {
    int ret = 0, cnt = 0;
    vst[u] = true;

    for (auto p : adj[u]) {
        int v = p.first, w = p.second;
        if (vst[v]) continue;
        int c_ret = dfs(v);
        if (c_ret < 0) continue;
        cnt++;
        ret += c_ret;
    }
    if (is_apt[u]) {
        ans += ret + 1;
        return 0;
    }
    ret++;
    if (cnt > 1) {
        ans += ret;
        return 0;
    } else if (cnt == 1) {
        return ret;
    }
    return -1;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // apt
    for (int i = 0; i < k; i++) {
        int u;
        cin >> u;
        u--;
        is_apt[u] = 1;
    }
    // sol
    dfs(0);
    cout << ans << '\n';
}