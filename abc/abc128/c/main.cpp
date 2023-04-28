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

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> S(m);
    rep(i,0,m) {
        int k; cin >> k;
        rep(j,0,k) {
            int s; cin >> s;
            s--;
            S[i].push_back(s);
        }
    }
    vector<int> p(m);
    rep(i,0,m) cin >> p[i];
    int cnt = 0;
    //1 << nですよ
    for (int bit = 0; bit < 1 << n; bit++) {
        bool flag = true;
        rep(i,0,m) {
            int num = 0;
            rep(j,0,S[i].size()) {
                if (bit & 1 << S[i][j]) num++;
            }
            if (num % 2 != p[i]) flag = false;
        }
        cnt += (flag ? 1 : 0);
    }
    cout << cnt << endl;
}