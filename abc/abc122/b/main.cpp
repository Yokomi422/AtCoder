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

int main() {
    string s; cin >> s;
    int ans = 0;
    rep(i,0,s.size()) {
        rep(j,1,s.size() - i + 1) {
            string T = s.substr(i,j);
            int cnt = 0;
            for (auto moji: T) {
                if (moji == 'A' | moji == 'C' | moji == 'G' | moji == 'T') cnt++;
                else break;
            }
            chmax(ans,cnt);
        }
    }
    cout << ans << endl;
}