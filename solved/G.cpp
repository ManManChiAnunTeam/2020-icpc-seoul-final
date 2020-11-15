#include <bits/stdc++.h>

#define INF 40000000000000000LL

using namespace std;
using ll = long long;

int main() {
    // freopen("input/1.in", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    ll d;
    cin >> n >> d;

    vector<ll> x(n+1);
    for(int i=1; i<=n; i++) {
        cin >> x[i];
    }

    vector<ll> move(n+1);

    // first
    ll m = INF, M = -INF;
    for(int i=1; i<=n; i++) {
        move[i] = (i-1) * d - x[i];
        m = min(m, move[i]);
        M = max(M, move[i]);
    }
    ll l = - (m + M);
    ll ans1 = 0;
    for(int i=1; i<=n; i++) {
        ans1 = max(ans1, abs(l + 2 * move[i]));
    }

    // second
    m = INF, M = -INF;
    for(int i=1; i<=n; i++) {
        move[i] = (n-i) * d - x[i];
        m = min(m, move[i]);
        M = max(M, move[i]);
    }
    l = - (m + M);
    ll ans2 = 0;
    for(int i=1; i<=n; i++) {
        ans2 = max(ans2, abs(l + 2 * move[i]));
    }

    ll ans = min(ans1, ans2);
    cout << ans / 2;
    if(ans % 2 == 0) cout << ".0";
    else cout << ".5";

    // cout << fixed;
    // cout.precision(1);
    // cout << min(ans1, ans2);
}