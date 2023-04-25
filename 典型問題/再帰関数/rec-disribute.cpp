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

using namespace std;
#define rep(i,k, n) for (int i = k; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;
using ld = long double;
const ld EPS = 1e-14;
typedef pair<int, int> P;

template<typename T> void chmax(T &a,T b) {
    if (a < b) a = b;
}
template<typename T> void chmin(T &a,T b) {
    if (a > b) a = b;
}

int n,x;
vector<int> a;

//再帰
bool dfs(int i,int w) {
    if (i == 0) {
        if (w == 0) return true;
        else return false;
    }
    if (dfs(i-1,w)) return true;
    if (dfs(i-1,w-a[i-1])) return true;
    return false;
}

int main() {
    cin >> n >> x;
    a.resize(n);
    rep(i,0,n) cin >> a[i];
    cout << ((dfs(n,x) ? "Yes": "No")) << endl;
}