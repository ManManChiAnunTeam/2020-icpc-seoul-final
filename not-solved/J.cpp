#include <bits/stdc++.h>
#define MAXN 501

using namespace std;

vector<int> sw[MAXN], lt[MAXN];
vector<int> ans[MAXN];
bool sw_on[MAXN], lt_on[MAXN];
int now;

bool dfs(int i) {  // 스위치 i
    if(sw_on[i]) return false;

    sw_on[i] = true;
    ans[now].push_back(i);
    for(int j : sw[i]) {
        lt_on[j] = !lt_on[j];
    }
    bool good = true;
    for(int j : sw[i]) {
        if(!lt_on[j]) continue;
        for(int s : lt[j]) {
            good = good & dfs(s);
        }
    }

    ans[now].pop_back();
    sw_on[i] = false;
    for(int j : sw[i]) {
        lt_on[j] = !lt_on[j];
    }
    if(good) return true;
    return false;
}

int main() {
    freopen("input/1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                sw[i].push_back(j);
                lt[j].push_back(i);
            }
        }
    }
    bool fail = false;
    for (now = 1; now <= n; now++) {
        memset(sw_on, 0, sizeof(bool)*MAXN);
        memset(lt_on, 0, sizeof(bool)*MAXN);

        bool t = false;
        for(int s : lt[now]) {
            t = t | dfs(s);
            if(t) {
                break;
            }
        }
        if(!t) {
            fail = true;
            break;
        }
    }

    if(fail) cout << -1;
    else {
        for(int i=1; i<=n; i++) {
            for(int a : ans[i]) {
                cout << a << ' ';
            }
            cout << '\n';
        }
    }
}