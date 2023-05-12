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

//全ての要素が同じか判定する関数
bool isSame(string str) {
    return all_of(str.begin(),str.end(),[str](char c){return c == str[0];});
}

int main() {
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i < 555555 + 1; i++) {
        if (isSame(to_string(i))) {
            cnt++;
            if (cnt == n) {
                cout << i << endl;
                return 0;
            }
        }
    }
}