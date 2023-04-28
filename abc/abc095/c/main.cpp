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

int main() {
    ll a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    ll ans = INF;
    ll limit = max(x,y);
    for (ll i = 0; i <= 2 * limit + 1; i += 2) {
        ll X = x - i / 2;
        ll Y = y - i / 2;
        if (X < 0 && Y > 0) {
            chmin(ans, b * Y + i * c);
            continue;
        }
        else if (X > 0 && Y < 0) {
            chmin(ans,a * X + i * c);
            continue;
        }
        else if (X <= 0 && Y <= 0) {
            chmin(ans,i * c);
            continue;
        }
        chmin(ans,a * X + b * Y + i * c);
    }
    cout << ans << endl;
}