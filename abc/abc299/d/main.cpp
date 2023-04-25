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
    cin >> N;

    int prev_bit, cur_bit;

    // 最初のビットを尋ねる
    cout << "? 1" << endl;
    cin >> prev_bit;

    // ビットのインデックスの増分を管理する変数を用意
    int step = 1;

    // 20回の質問に制限があるため、2^stepを増加させながら質問を行う
    for (int i = 1; i < 20; ++i) {
        int next_index = 1 + step;

        // 次のビットを尋ねる
        cout << "? " << next_index << endl;
        cin >> cur_bit;

        // 現在のビットが前のビットと異なる場合、条件を満たす整数pが見つかりました。
        if (cur_bit != prev_bit) {
            cout << "! " << next_index - 1 << endl;
            return 0;
        }

        prev_bit = cur_bit;
        step *= 2;
    }

    // 最後に一度だけ質問を行い、条件を満たすpを見つける
    for (int i = step / 2; i < N; ++i) {
        cout << "? " << i << endl;
        cin >> cur_bit;

        if (cur_bit != prev_bit) {
            cout << "! " << i - 1 << endl;
            return 0;
        }
        prev_bit = cur_bit;
    }

    return 0;
}
