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
    int w;
    Edge(int to, int w) : to(to),w(w) {};
};

int main() {
    int h,w; cin >> h >> w;
    vector<vector<int>> c(10,vector<int>(10));
    rep(i,0,10) rep(j,0,10) cin >> c[i][j];
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,0,h) rep(j,0,w) cin >> a[i][j];
    //Dijkstra
    vector<ll> dist(10,INF);
    dist[1] = 0;
    
}