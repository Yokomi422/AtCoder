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
    ll from;
    ll to;
    ll cost;
    Edge() : from(0), to(0), cost(0) {}
};

int main() {
    int v,e,r; cin >> v >> e >> r;
    //各頂点の最短距離
    vector<ll> dist(v,INF);
    dist[r] = 0;
    //辺の入力
    vector<Edge> edges;
    rep(i,0,e) {
        struct Edge add;
        cin >> add.from >> add.to >> add.cost;
        edges.push_back(add);
    }
    rep(i,0,v) rep(j,0,e) {
        struct Edge e = edges[j];
        if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
            dist[e.to] = dist[e.from] + e.cost;
            if (i == v-1) {
                cout << "NEGATIVE CYCLE" << endl;
                return 0;
            }
        }
    }
    rep(i,0,v) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}