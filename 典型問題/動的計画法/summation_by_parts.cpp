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

//https://algo-method.com/tasks/337

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> W(n);
    rep(i,n) cin >> W[i];
    bool dp[110][10010];
    rep(i,n+1) {
        rep(j,m+1) dp[i][j] = false;
    }
    dp[0][0] = true;
    //誤りポイント [jの範囲はm+1ではない。二個目のif文の位置を下げる(W[i]を足すという操作は上がtrueであることが前提)。
    rep(i,n) {
        rep(j,m+1) {
            if (dp[i][j]) {
                dp[i+1][j] = true;
                if (j + W[i] <= m) {
                    dp[i+1][j + W[i]] = true;
                }
            }
        }
    }
    if (dp[n][m]) cout << "Yes" << endl;
    else cout << "No" << endl;
}