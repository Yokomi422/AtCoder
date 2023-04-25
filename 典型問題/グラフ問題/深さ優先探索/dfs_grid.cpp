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

//グリッドタイプの問題をグラフの問題として解く。


//迷路の状態を記録する
vector<vector<char>> maze;
vector<vector<bool>> seen;
//スタートとゴールを記録しておくためのペア
P s,g;
//上下左右を探索するため
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int h,w;
//場所を引数にとって再帰関数を呼び出す
void dfs(P p) {
    seen[p.first][p.second] = true;
    rep(i,4) {
        int x = p.second + dx[i];
        int y = p.first + dy[i];
        //枠外は除外
        if (x < 0 || x >= w || y < 0 || y >= h) continue;
        //進めない箇所も除外
        if (maze[y][x] == '#') continue;
        //探索済みも除外
        if (seen[y][x]) continue;
        dfs(make_pair(y,x));
    }
}

int main() {
    cin >> h >> w;
    //'.'で初期化
    maze.assign(h,vector<char>(w,'.'));
    rep(i,h) {
        rep(j,w) {
            //push_backしても良さそう
            cin >> maze[i][j];
            if (maze[i][j] =='s') s = make_pair(i,j);
            else if (maze[i][j] == 'g') g = make_pair(i,j);
        }
    }
    //assignで初期化 h全てをfalseで初期化
    seen.assign(h, vector<bool>(w,false));
    dfs(s);
    if (seen[g.first][g.second]) cout << "Yes" << endl;
    else cout << "No" << endl;
}