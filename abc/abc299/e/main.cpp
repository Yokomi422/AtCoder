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

ll INF = 1LL<<60;

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
}
template<typename T> void chmin(T &a,T b) {
    if (a > b) a = b;
}

vector<vector<int>> adj;
vector<int> color;
vector<int> dist;

void bfs(int start) {
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == 0) {
                color[v] = 3 - color[u];
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    adj.resize(N + 1);
    color.resize(N + 1);
    dist.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> p(K), d(K);
    for (int i = 0; i < K; ++i) {
        cin >> p[i] >> d[i];
    }

    bfs(p[0]);

    bool valid = true;
    for (int i = 0; i < K; ++i) {
        if (dist[p[i]] != d[i]) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 1; i <= N; ++i) {
            cout << color[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
