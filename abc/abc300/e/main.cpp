#include <iostream>
#include <map>
#include <vector>

const long long MOD = 998244353;

std::map<int, int> prime_factors(int n) {
    std::map<int, int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) factors[n]++;
    return factors;
}

long long mod_pow(long long x, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int N;
    std::cin >> N;

    auto factors = prime_factors(N);

    long long ans = 1;
    for (const auto& factor : factors) {
        int p = factor.first, cnt = factor.second;
        std::vector<long long> dp(cnt + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= 6; ++i) {
            for (int j = cnt; j >= 0; --j) {
                for (int k = 1; k <= i && j + k <= cnt; ++k) {
                    dp[j + k] += dp[j] * mod_pow(6, MOD - 2, MOD) % MOD;
                    dp[j + k] %= MOD;
                }
            }
        }
        ans *= dp[cnt];
        ans %= MOD;
    }
    std::cout << ans << std::endl;

    return 0;
}
