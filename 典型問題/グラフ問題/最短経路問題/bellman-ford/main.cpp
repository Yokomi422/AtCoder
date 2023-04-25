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

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
}
template<typename T> void chmin(T &a,T b) {
    if (a > b) a = b;
}

struct Edge {
    int from;
    int to;
    int cost;
};

int main() {
    int v,e,s,g; cin >> v >> e >> s >> g;
    vector<int> dist(v);
    //頂点の移動情報
    vector<Edge> edges;
    //???
    fill(dist.begin(), dist.end(), 1e9);
    dist[s] = 0;
    //辺の入力
    rep(i,0,e) {
        struct Edge add;
        //変数には.で入力する
        cin >> add.from >> add.to >> add.cost;
        edges.push_back(add);
    }
    rep(i,0,v) {
        rep(j,0,(int) edges.size()) {
            struct Edge e = edges[j];
            if (dist[e.from] != 1e9 && dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == v - 1) {
                    break;
                }
            }
        }
    }
    //求める点への距離を出力
}