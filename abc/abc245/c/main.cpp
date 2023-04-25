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

ll INF = 1LL<<60;

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
}
template<typename T> void chmin(T &a,T b) {
    if (a > b) a = b;
}

int main() {
    int n,K; cin >> n >> K;
    vector<vector<int>> ab(n,vector<int>(2));
    rep(i,0,n) cin >> ab[i][0];
    rep(i,0,n) cin >> ab[i][1];
    bool cur[2] = {true,true};
    bool next[2];
    rep(i,0,n-1) {
        next[0] = next[1] = false;
        rep(j,0,2) if (cur[j]) {
            rep(k,0,2) {
                if (abs(ab[i][j] - ab[i+1][k]) <= K) next[k] = true;
            }
        }
        rep(j,0,2) cur[j] = next[j];
    }
    if (cur[0] || cur[1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}


// 圧縮
// forループに使う変数とcinする変数を同じにしてはダメ