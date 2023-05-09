#include <iostream>
#include <vector>

typedef long long ll;

std::vector<ll> sieve(ll limit) {
    std::vector<bool> is_prime(limit + 1, true);
    std::vector<ll> primes;

    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

int main() {
    ll N;
    std::cin >> N;

    ll limit = N / 4; // Since a = 2 is the smallest prime
    std::vector<ll> primes = sieve(limit);
    int count = 0;

    for (const auto& a : primes) {
        ll b_c_limit = N / (a * a);
        for (size_t i = 0; i < primes.size() && primes[i] < b_c_limit; i++) {
            for (size_t j = i + 1; j < primes.size() && primes[i] * primes[j] <= b_c_limit; j++) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
