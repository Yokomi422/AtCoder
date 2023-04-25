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

ll INF = 1LL<<60;

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
}
template<typename T> void chmin(T &a,T b) {
    if (a > b) a = b;
}

int main() {
    int n, m; cin >> n >> m;
    vector<ll> a(m+2);
    a[0] = 0;
    rep(i, 0, m) cin >> a[i+1];
    a[m+1] = n+1;
    sort(a.begin(), a.end());

    // 最小の k を求める
    ll k = INF;
    for (int i = 0; i < m + 1; i++) {
        //a[i]が1の時のヘッジ
        if (a[i+1] - a[i] - 1 > 0) {
            k = min(k, a[i+1] - a[i] - 1);
        }
    }

    // 答えを求める
    int ans = 0;
    for (int i = 0; i < m + 1; i++) {
        // ceil((a[i+1] - a[i] - 1) / k) を求める
        ans += (a[i+1] - a[i] - 1 + k - 1) / k;
    }

    cout << ans << endl;
}

//0とn+1を加えるとわかりやすい
//kは最小の区間の長さ