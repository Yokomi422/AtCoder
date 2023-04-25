#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;

//ユークリッドの互除法を作る.a > bと仮定する.
long long GCD(long long a, long long b) {
    if (b==0) return a;
    else return GCD(b,a%b);
}
long long LCM(ll a, ll b) {
    return a*b/gcd(a,b);
}

int main() {
    int a,b;
    cin >> a >> b;
    cout << LCM(a,b) << endl;
}