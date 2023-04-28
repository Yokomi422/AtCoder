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
    ll to;
    ll w;
    Edge(ll to, ll w) : to(to),w(w) {};
};

int main() {
    ll v,e,r; cin >> v >> e >> r;
    vector<vector<Edge>> G(v);
    rep(i,0,e) {
        ll s,t,d; cin >> s >> t >> d;
        G[s].push_back(Edge(t,d));
    }
    //Dijkstra
    vector<bool> visited(v,false);
    vector<ll> dist(v,INF);
    dist[r] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<P>> pq;
    pq.emplace(dist[r],r);
    while (!pq.empty()) {
        ll now = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        visited[now] = true;
        for (auto g: G[now]) {
            if (!visited[g.to] && dist[g.to] > dist[now] + g.to) dist[g.to] = dist[now] + g.to;
        }
    }
    rep(i,0,v) cout << dist[i] << endl;
    return 0;
}