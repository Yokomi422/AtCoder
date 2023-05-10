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

//n < 20 -> bit
//( -> 0 ) -> 1

bool judge(string s) {
    int cnt = 0;
    rep(i,0,s.size()) {
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false; 
    }
    if (cnt == 0) return true;
    else return false;
}

int main() {
    int n;
    cin >> n;
    if (n % 2 == 1) return 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        string s = "";
        for (int i = n - 1; i >= 0; i--) {
            if (bit & 1 << i) s += ')';
            else s += '(';
        }
        if (judge(s)) cout << s << endl;
    }
}