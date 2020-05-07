#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// Sieve of Eratosthenes
// 素因数分解 1e7くらいまで
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n = 1) : n(n), f(n + 1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; i++) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i + i; j <= n; j += i)
        if (!f[j]) f[j] = i;
    }
  }
  bool isPrime(int x) { return f[x]; }
  vector<int> factorList(int x) {  // prime factors
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factors(int x) {
    vector<int> f = factorList(x);
    if (f.size() == 0) return {};
    vector<P> res(1, P(f[0], 0));
    for (int p : f) {
      if (res.back().first == p)
        res.back().second++;
      else
        res.emplace_back(p, 1);
    }
    return res;
  }
};

int main() {
  Sieve sieve(1e7);
  int n;
  cin >> n;

  vector<P> factors = sieve.factors(n);
  printf("%d:", n);
  for (P f : factors) rep(i, f.second) printf(" %d", f.first);
  cout << endl;
  return 0;
}