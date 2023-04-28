#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <cmath>
#include <ctime>
#include <numeric>
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

using namespace std;
#define rep(i,k, n) for (int i = k; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ld EPS = 1e-14;
typedef pair<int, int> P;

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
    
}
template<typename T> bool chmin(T &a,T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

//edgeの大きさが１の最短経路問題は幅優先探索
struct Edge {
    int to;
    ll w;
    Edge(int to, int w) : to(to), w(w) {};
};

using Graph = vector<vector<Edge>>;


int main() {
    int n,m,s; cin >> n >> m >> s;
    Graph G(n);
    rep(i,0,m) {
        int a,b,w; cin >> a >> b >> w;
        G[a].push_back(Edge(b,w));
    }
    // Dijkstra
    //その点は最短距離ですか?
    //幅優先探索の応用例
    vector<bool> visited(n,false);
    vector<ll> dist(n, 1e18);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(dist[s],s));
    while (!pq.empty()) {
        int now = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        visited[now] = true;
        for (auto g: G[now]) {
            if (!visited[g.to] && dist[now] + g.w < dist[g.to]) {
                dist[g.to] = dist[now] + g.w;
                pq.emplace(dist[g.to],g.to);
            } 
        } 
    }
}