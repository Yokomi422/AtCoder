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

void vertical_shift(vector<string>& grid, int H) {
    for (int j = 0; j < H - 1; ++j) {
        swap(grid[j], grid[j + 1]);
    }
}

void horizontal_shift(vector<string>& grid, int W) {
    for (auto& row : grid) {
        row = row.substr(1) + row[0];
    }
}

bool is_equal(const vector<string>& grid1, const vector<string>& grid2) {
    return grid1 == grid2;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H), B(H);
    for (int i = 0; i < H; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < H; ++i) {
        cin >> B[i];
    }

    for (int s = 0; s < H; ++s) {
        for (int t = 0; t < W; ++t) {
            if (is_equal(A, B)) {
                cout << "Yes" << endl;
                return 0;
            }
            horizontal_shift(A, W);
        }
        vertical_shift(A, H);
    }

    cout << "No" << endl;
    return 0;
}
