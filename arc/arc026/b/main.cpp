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

vector<int> divisor(ll &n) {
    vector<int> divs;
    for (int i = 2; i * i <= n; i++) {
        if (n%i != 0) continue;
        else {
            while (n%i == 0) {
                n /= i;
            }
            divs.push_back(i);
        }
    }
    if (n != 1) divs.push_back(n);
    return divs;
}

int main() {
    ll n; cin >> n;
    ll ans = n;
    vector<int> div = divisor(n);
    rep(i,0,div.size()) {
        ans *= (div[i] - 1);
        ans /= div[i];
    }
    rep(i,0,div.size()) cout << div[i] << endl;
}