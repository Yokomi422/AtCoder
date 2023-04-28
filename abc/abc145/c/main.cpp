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
//階乗
int factorial(int n) {
    if (n == 0) return 1;
    return factorial(n-1) * n;
}

int main() {
    int n; cin >> n;
    long double sm = 0;
    vector<int> x(n), y(n);
    rep(i,0,n) cin >> x[i] >> y[i];
    int prev_x = 0, prev_y = 0;
    //順列全探索をするための配列を作る
    vector<int> N(n);
    rep(i,0,n) N[i] = i;
    //順列全探索
    do {
        rep(i,0,n) {
            if (i == 0) {
                prev_x = x[N[i]]; prev_y = y[N[i]];
                continue;
            }
            long double d = (x[N[i]] - prev_x)*(x[N[i]] - prev_x) + (y[N[i]] - prev_y)*(y[N[i]] - prev_y);
            sm += sqrt(d);
        }
    }
    while (next_permutation(N.begin(), N.end()));
    cout << fixed << setprecision(10) << sm / factorial(n)  << endl;
}