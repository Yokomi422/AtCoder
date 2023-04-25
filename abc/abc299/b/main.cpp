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
    int n, t;
    cin >> n >> t;
    vector<int> c(n);
    rep(i,0,n) cin >> c[i];
    vector<int> r(n);
    rep(i,0,n) cin >> r[i];
    int ans = 1;
    int mx = 0;
    //tがあったか
    bool ok = false;
    //tがなかった時、対策
    int sub_mx = r[0];
    int sub_ans = 1;
    rep(i,0,n) {
        if (i > 0 && c[i] == c[0] && r[i] > sub_mx) {
            if (r[i] > sub_mx) {
                sub_mx = r[i];
                sub_ans = i + 1;
            }
        }
        if (c[i] == t) {
            ok = true;
            if (mx < r[i]) {
                mx = r[i];
                ans = i + 1;
            }
        }
    }
    if (!ok) {
        cout << sub_ans << endl;
        return 0;
    }
    cout << ans << endl;
}