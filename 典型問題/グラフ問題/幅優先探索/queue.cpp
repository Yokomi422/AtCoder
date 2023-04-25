#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;
//vectorで実行すると一つずれる。配列で実行したほうがいいかも
//https://algo-logic.info/bfs/
int main() {
    int v,e,s,t;
    cin >> v >> e >> s >> t;
    Graph G(v);
    rep(i,e) {
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