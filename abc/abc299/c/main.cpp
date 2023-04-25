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
    int N;
    string S;
    cin >> N >> S;

    int max_level = -1;

    for (int i = 0; i < N - 1; ++i) {
        if (S[i] == 'o' && S[i + 1] == '-') {
            int level = 0;
            while (i - level >= 0 && S[i - level] == 'o') {
                level++;
            }
            max_level = max(max_level, level);
        } else if (S[i] == '-' && S[i + 1] == 'o') {
            int level = 0;
            while (i + 1 + level < N && S[i + 1 + level] == 'o') {
                level++;
            }
            max_level = max(max_level, level);
        }
    }

    cout << max_level << endl;
    return 0;
}
