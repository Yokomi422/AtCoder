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



int main() {
    int n,m; cin >> n >> m;
    Graph G(n);
    rep(i,0,m) {
        int a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //bfs
    vector<int> dist(n,-1);
    queue<int> que;
    //初期化
    que.push(0);
    dist[0] = 0;
    cout << 0 << endl;
    
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (auto g: G[now]) {
            if (dist[g] == -1) {
                dist[g] = dist[now] + 1;
                que.push(g);
            }
        }
    }
    vector<set<int>> output(n);
    //outputは上のコードに含められたと思う
    rep(i,0,n) {
        if (dist[i] == -1) continue;
        output[dist[i]].insert(i);
    }
    rep(i,0,n) {
        if (output[i].size() == 0) break;
        for (auto o: output[i]) {
            cout << o << " ";
        }
        cout << endl;
    }
}