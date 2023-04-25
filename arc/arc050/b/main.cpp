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

ll r,b,x,y;

bool check(ll mid) {
    //引き算をするときは、注意しよう
    ll R = r - mid;
    ll B = b - mid;
    if (R < 0 || B < 0) return false;
    //上でmidを引いたのにここでも引くのはやめよう
    return R / (x-1) + B / (y - 1) >= mid;
}

//最大値最小値を求める問題にも二分探索は使える

int main() {
    cin >> r >> b >> x >> y;
    ll ok = 0,ng = 1e18;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        //単調性を利用した二分探索では、ok = mid + 1とかはしてはいけない
        if (check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}