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
    int n,t; cin >> n >> t;
    vector<int> c(n);
    rep(i,0,n) cin >> c[i];
    vector<int> r(n);
    rep(i,0,n) cin >> r[i];
    //勝者のid
    int ans = 0;
    int max = 0;
    //Tが出なかった時用
    int sub_ans = 1;
    int sub_max = r[0];
    rep(i,0,n) {
        if (c[i] == t) {
            if (max < r[i]) {
                ans = i + 1;
                chmax(max,r[i]);
            }
        }
        if (i != 0) {
            if (c[0] == c[i] && sub_max < r[i]) {
                sub_ans = i + 1;
                chmax(sub_max,r[i]);
            } 
        }
    }
    if (ans == 0) {
        cout << sub_ans << endl;
    }
    else cout << ans << endl;
}