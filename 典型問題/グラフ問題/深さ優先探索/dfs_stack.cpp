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


//https://algo-logic.info/dfs/
int main() {
    int v,e,s,t;
    cin >> v >> e >> s >> t;
    Graph G(v);
    rep(i,e) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    vector<bool> seen(v,false);
    stack<int> todo;
    seen[s] = true;
    todo.push(s);
    while (todo.size() != 0) {
        int now = todo.top();
        todo.pop();
        for (int dot: G[now]) {
            if (!seen[dot]) {
            seen[dot] = true;
            todo.push(dot);
            }
        }
    }
    if (seen[t]) cout << "yes" << endl;
    else cout << "no" << endl;
}