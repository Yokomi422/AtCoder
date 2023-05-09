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

const ll INF = 1LL<<60;

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
}
template<typename T> void chmin(T &a,T b) {
    if (a > b) a = b;
}

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to),w(w) {};
};

int cumulative_sum[100009];

//TLE解答

// int main() {
//     int n,q; cin >> n >> q;
//     string s; cin >> s;
//     rep(i,2,n + 1) {
//         string sub = s.substr(0,i);
//         int cnt =  0;
//         int pos = 0;
//         while ((pos = sub.find("AC", pos)) != string::npos) {
//             if (pos <= i - 2) {
//                 cnt++;
//                 pos += 2;
//             }
//             else break;
//         }
//         cumulative_sum[i] = cnt;
//     }
//     rep(i,0,q) {
//         int l,r; cin >> l >> r;
//         cout << cumulative_sum[r] - cumulative_sum[l] << endl;
//     }
// }



int main() {
    int n,q; cin >> n >> q;
    string s; cin >> s;
    rep(i,0,n + 1) {
        if (i < n && s[i] == 'A' && s[i + 1] == 'C') {
            cumulative_sum[i + 2] = cumulative_sum[i + 1] + 1;
        }
        else cumulative_sum[i + 2] = cumulative_sum[i + 1];
    }
    rep(i,0,q) {
        int l,r; cin >> l >> r;
        cout << cumulative_sum[r] - cumulative_sum[l] << endl;
    }
}