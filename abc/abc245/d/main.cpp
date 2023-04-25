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
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    vector<int> c(n+m+1);
    rep(i,0,n+1) cin >> a[i];
    rep(i,0,n+m+1) cin >> c[i];
    //答えの係数数列
    vector<int> b;
    int head = n + m;
    rep(i,0,m+1) {
        int b_index = c[head] / a[n];
        b.push_back(b_index);
        rep(j,0,n+1) c[head-j] -= b_index * a[n-j];
        head--;
    }
    reverse(b.begin(), b.end();
    for (auto x : b) cout << x << " ";
}