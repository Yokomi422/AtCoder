#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;
using P = pair<int ,int>;

//next_permutationを使う。next_permutation(vec.begin(), vec.end())と書き、配列vec(vector)は昇順にソートされている必要がある。
//https://qiita.com/siser/items/a91022071b24952d27d9
int main() {
    int n;
    cin >> n;
    vector<int> N;
    //昇順のリストを作る
    rep(i,n) N.push_back(i);
    do {
        for (auto i: N) cout << i << " ";
        cout << endl;
    }
    while(next_permutation(N.begin(),N.end()));
}