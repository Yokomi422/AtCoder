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

int howManyDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n%i == 0) {
            cnt++;
            if (i != n / i) cnt++;
        }
    }
    return cnt;
}

int main() {
    int n; cin >> n;
    int cnt = 0;
    rep(i,1,n+1) {
        if (howManyDivisors(i) == 8 && i%2 == 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}