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
#define rep(i,k, n) for (int i = k; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int n,x;
vector<int> a;

//深さ優先探索
bool dfs(int i, int w) {
    if (i == n) {
        if (w == x) return true;
        else return false;
    }
    //選ぶ
    if (dfs(i+1,w + a[i])) return true;
    //選ばない
    if (dfs(i+1,w)) return true;
    return false;
}

int main() {
    cin >> n >> x;
    a.resize(n);
    rep(i,0,n) cin >> a[i];
    cout << (dfs(0,0) ? "Yes":"No") << endl;
}