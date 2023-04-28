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

bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int cumsum[100009];

int main() {
    rep(i,0,100009) cumsum[i] = 0;
    int q; cin >> q;
    rep(i,1,100000) {
        if (i % 2 == 0) {
            cumsum[i] = cumsum[i-1];
            continue; 
        }
        else cumsum[i] = cumsum[i-1];
        if (i % 2 == 1 && isPrime(i)) {
            if (isPrime((i + 1) / 2)) {
                cumsum[i] += 1;
            }
        }
    }
    rep(i,0,q) {
        int l,r; cin >> l >> r;
        cout << cumsum[r] - cumsum[l-1] << endl;
    }
}