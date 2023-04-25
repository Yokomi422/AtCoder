#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;
using P = pair<int ,int>;

//スタートからゴールまで最短距離を求める問題を解くよ https://atcoder.jp/contests/abc007/tasks/abc007_3
const int INF = 2100100100;
int r,c;
vector<vector<char>> maze;
vector<vector<int>> dist; //距離を保存しておく
int sx,sy,gx,gy;

int main() {
    cin >> r >> c >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;

    dist.assign(r,vector<int>(c,INF));
    maze.assign(r,vector<char>(c,'.'));
    rep(i,r) {
        rep(j,c) cin >> maze[i][j];
    }
    queue<pair<int ,int>> que;
    que.push(make_pair(sy,sx));
    dist[sy][sx] = 0;
    while (que.size() != 0) {
        P now = que.front();
        que.pop();
        if (now.first == gy && now.second == gx) break;
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        rep(i,4) {
            int x = now.second + dx[i];
            int y = now.first + dy[i];
            if (y < 0 || x < 0 || x >= c || y >= r) continue;
            if (maze[y][x] == '#') continue;
            if (dist[y][x] != INF) continue;
            que.push(make_pair(y,x));
            dist[y][x] = dist[now.first][now.second] + 1;
        }
    }
    cout << dist[gy][gx] << endl;
}