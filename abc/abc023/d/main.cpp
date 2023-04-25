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

ll n;
vector<ll> h;
vector<ll> s;

bool check(ll mid) {
    rep(i,0,n) {
        vector<bool> shooted(n,false);
        
    }
}

int main() {
    cin >> n;
    h.resize(n); 
    s.resize(n);
    rep(i,0,n) cin >> h[i] >> s[i];
    ll ng = 0, ok = INF;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;

    }
}