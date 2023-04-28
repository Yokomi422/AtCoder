#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;

//https://qiita.com/drken/items/56a6b68edef8fc605821#fnref1
//区間クエリの問題で効力を発揮するよ
//考えているより1つ大きなindexを用意してS[0] = 0にする
int main() {
    int N; cin >> N; // 配列サイズ
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i]; // a の入力

    // 累積和
    vector<int> s(N+1, 0); // s[0] = 0 になる
    for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];
    // 区間 [left, right) の総和を求める
    int left, right;
    cin >> left >> right;
    cout << s[right] - s[left] << endl;
}