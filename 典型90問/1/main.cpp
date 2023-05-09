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

// 最小値ということは、全てがある値以上になるということ
//判定問題・・・cnt >= k + 1ならok

int n,l,k; 
vector<int> a;

bool judge(int mid) {
    int cnt = 0;
    int prev = 0;
    rep(i,0,n) {
        if (mid <= a[i] - prev) {
            cnt++;
            prev = a[i];
        }
    }
    if (l - prev >= mid) cnt++;
    if (cnt >= k + 1) return true;
    else return false;
}


int main() {
    cin >> n >> l >> k;
    a.resize(n);
    rep(i,0,n) cin >> a[i];
    int left = 0, right = l;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (judge(mid)) left = mid;
        else right = mid;
    }
    cout << left << endl;
}