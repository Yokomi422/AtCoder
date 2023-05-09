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

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    string ans = "";
    int min_len = min(word1.size(),word2.size());
    int max_len = max(word1.size(),word2.size());
    rep(i,0,min_len) {
        ans += word1[i];
        ans += word2[i];
    }
    if (min_len == max_len) {
        cout << ans << endl;
        return 0;
    }
    string s = "";
    if (word1.size() > word2.size())  s = word1;
    else  s = word2;
    rep(i,min_len,max_len) {
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}

