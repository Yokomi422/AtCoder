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

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

int main() {
    int h,w; cin >> h >> w;
    int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
    vector<string> s(h);
    rep(i,0,h) cin >> s[i];
    //bfs
    vector<vector<int>> dist(h,vector<int>(w,-1));
    queue<pair<int,int>> que;
    //初期化
    que.emplace(x0,y0);
    dist[x0][y0] = 0;
    //bfs開始
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        //for ループを[0,4)で回す
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            //場外に行っていたら、パスする
            if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w || s[next_x][next_y] == 'B' || dist[next_x][next_y] != -1) continue;
            dist[next_x][next_y] = dist[x][y] + 1;
            que.emplace(next_x,next_y);
        }
    }
    cout << dist[x1][y1] << endl;
}