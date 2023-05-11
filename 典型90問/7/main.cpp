#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <cmath>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cassert>
#include <bitset>
#include <typeinfo>
#include <utility>
#include <list>
#include <numeric>

using namespace std;
#define rep(i,k, n) for (int i = k; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;
using ld = long double;
const ld EPS = 1e-14;
typedef pair<int, int> P;

const ll INF = 1LL<<60;

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
}
template<typename T> void chmin(T &a,T b) {
    if (a > b) a = b;
}

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to),w(w) {};
};

int dfs(int v, const vector<vector<int>> &children) {
    int cnt = 0;
    for (auto child: children[v]) {
        cnt++;
        cnt += dfs(child, children);
    }
    return cnt;
}


int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    sort(a.begin(), a.end());
    int q; cin >> q;
    rep(i,0,q) {
        ll b; cin >> b;
        int idx = lower_bound(a.begin(), a.end(), b) - a.begin();
        ll res = INF;
        if (idx < n) chmin(res,abs(b - a[idx]));
        if (idx > 0) chmin(res,abs(b - a[idx - 1]));
        cout << res << endl;
    }
    return 0;
}