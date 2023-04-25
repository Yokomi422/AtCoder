#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;

//https://algo-method.com/tasks/308
int main() {
    int n,w;
    cin >> n >> w;
    int weight[110],value[110];
    //二次元配列は最初の引数が行数です。重さはwの最大値+α
    int dp[110][10010];
    rep(i,n) cin >> weight[i];
    rep(i,n) cin >> value[i];
    //dp初期条件
    //exit status139のエラー ①intの範囲を超えてしまっている　②配列参照外
    //value[i]の位置に注意
    rep(i,w+1) dp[0][i] = 0;
    rep(i,n) {
        rep(j,w+1) {
            if (j >= weight[i]) {
                dp[i+1][j] = max(dp[i][j-weight[i]] + value[i],dp[i][j]);
            }
            else dp[i+1][j] = dp[i][j];
        }
    }
    cout << dp[n][w] << endl;
}