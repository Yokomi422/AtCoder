#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;
using P = pair<int ,int>;

//next_permutationを使う。next_permutation(vec.begin(), vec.end())と書き、配列vec(vector)は昇順にソートされている必要がある。
//https://qiita.com/siser/items/a91022071b24952d27d9
int main() {
    int n,k,cnt = 0;
    cin >> n >> k;
    Graph T(n,vector<int>(n));
    rep(i,n) rep(j,n) cin >> T[i][j];
    vector<int> N;
    rep(i,n-1) N.push_back(i+1);
    do {
        vector<int> route;
        int sum = 0;
        rep(i,n-1) route.push_back(N[i]);
        sum += T[0][route[0]] + T[route[n-2]][0];
        rep(i,n-2) {
            sum += T[route[i]][route[i+1]];
        }
        if (sum == k) cnt += 1;
    }
    while(next_permutation(N.begin(),N.end()));
    cout << cnt << endl;
}