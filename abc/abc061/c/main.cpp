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

//累積和で解いてみる

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
}
template<typename T> void chmin(T &a,T b) {
    if (a > b) a = b;
}

//バケットソートの考えと使う n <- 1e5なのがポイント バケットソートは累積和とコラボする

const int MAX = 1e5 + 9;
//配列を初期化しないとランダムな値を持つことになり、CEになる可能性がある
int backet[MAX] = {0};
int partial[MAX] = {0};

//llとintを混ぜるときは注意する

// int main() {
//     vector<int> a = {1,2,3,4,5,7,8};
//     cout << *(a.begin()) << endl;
// }

// int main() {
//     int n,k; cin >> n >> k;
//     rep(i,0,n) {
//         int a,b; cin >> a >> b;
//         backet[a] += b;
//     }
//     partial = backet;

// }