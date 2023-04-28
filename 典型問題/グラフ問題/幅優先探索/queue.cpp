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
//vectorで実行すると一つずれる。配列で実行したほうがいいかも
//https://algo-logic.info/bfs/
int main() {
    int v,e,s,t;
    cin >> v >> e >> s >> t;
    Graph G(v);
    rep(i,0,e) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    //seenではなくてdistを-1にしてもいいね
    vector<bool> seen(v);
    queue<int> que;
    seen[s] = true;
    que.push(s);
    //que.empty()でも可
    while (que.size() != 0) {
        int now = que.front();
        que.pop();
        for (auto next: G[now]) {
            if (!seen[next]) {
                seen[next] = true;
                que.push(next);
            }

        }
    }
    if (seen[t]) cout << "yes" << endl;
    else cout << "no" << endl;
}