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


//解法１ 
//2 max_element
//3 pair<int,int>で<値,index ＋ 1>を持っておいてソートする

int main() {
    ll n; cin >> n;
    vector<pair<ll,ll>> ps;
    rep(i,0,n) {
        int h; cin >> h;
        ps.emplace_back(h,i + 1);
    }
    sort(ps.begin(), ps.end());
    cout << ps.back().second << endl;
}