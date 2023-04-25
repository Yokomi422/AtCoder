#include <iostream>
#include <string>
#include <algorithm> 
#include <cmath>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>
#include <set>
#include <tuple>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;
using P = pair<int, int>;

vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next: G[v]) {
        if (!seen[next]) dfs(G,next);
    }
}

int main() {
    int v,e,s,t;
    cin >> v >> e >> s >> t;
    Graph G(v);
    rep(i,e) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    seen.assign(v,false);
    dfs(G,s);
    if (seen[t]) cout << "yes" << endl;
    else cout << "no" << endl;
}