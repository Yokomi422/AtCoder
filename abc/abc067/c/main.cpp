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
ll MOD = 1e9 + 7;

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
}
template<typename T> void chmin(T &a,T b) {
    if (a > b) a = b;
}

vector<pair<ll,ll>> prime_factorize(ll n) {
    vector<pair<ll,ll>> res;
    for (ll i = 2; i * i <= n; i++) {
        if (n%i != 0) continue;
        ll index = 0;
        while (n%i == 0) {
            index++;
            n /= i;
        }
        res.emplace_back(i,index);
    }
    if (n != 1) res.emplace_back(n,1);
    return res;
}
  
int main() {
    ll n; cin >> n;
    ll ans = 1;
    for (auto ps: prime_factorize(n)) {
        ans *= ps.second%MOD;
        ans = ans%MOD;
    }
    cout << ans << endl;
}