max_element 配列の最大値のイテレータを返す max_element(a.begin(),a.end())

min_element 配列の最小値のイテレータを返す min_element(a.begin(),a.end()) O(n)

partial_sum 配列の累積和を計算する partial_sum(a.begin(),a.end(),b.begin()) 



nCrを計算する関数 返り値に対して、v[n][r]がnCrになる。
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

//階乗
int factorial(int n) {
    if (n == 0) return 1;
    return factorial(n-1) * n;
}