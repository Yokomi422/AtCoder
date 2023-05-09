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
using ll = long long;


// nCrを計算する関数 返り値に対して、v[n][r]がnCrになる。
vector<vector<long long>> comb(int n, int r) {
  vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

//役数の個数を求める
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

//約数列挙
vector<int> divisors(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

//素因数分解
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

//累乗を求める
ll power(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        ans *= a;
        b--;
    }
    return ans;
}

//等比数列の総和 a**b
ll sgp(ll a, ll b) {
    return (power(a, b + 1) - 1) / (a - 1);
}

//約数の総和
ll sum_divisors(ll n) {
    ll ans = 1;
    vector<pair<long long, long long>> pf = prime_factorize(n);
    for (int i = 0; i < pf.size(); i++) {
        ans *= sgp(pf[i].first,pf[i].second);
    }
    return ans;
}

//階乗
int factorial(int n) {
    if (n == 0) return 1;
    return factorial(n-1) * n;
}

//素数判定
bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

//エラトステネスの篩
vector<bool> Eratostheness(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * 2; j <= n; j += i) {
            isPrime[j] = false;
        }
    }
    return isPrime;
}

int main() {
}