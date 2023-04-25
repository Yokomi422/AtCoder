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
const ll MOD = 998244353;

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
}
template<typename T> void chmin(T &a,T b) {
    if (a > b) a = b;
}

//とにかくつけられるところには全て()をつける

int main() {
    ll a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
    ll upper = ((((a%MOD) * (b%MOD))%MOD) * (c%MOD))%MOD;
    ll lower = ((((d%MOD) * (e%MOD))%MOD) * (f%MOD))%MOD;
    cout << (upper + MOD - lower)%MOD << endl;
    //mod計算で- が入るときは注意
    return 0;
}