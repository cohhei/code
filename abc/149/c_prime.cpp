#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> f(n * 2 + 1);
  for (ll i = 2; i <= 2 * n; i++) {
    if (f[i]) continue;
    // primes.push_back(i);
    if (i >= n) {
      cout << i << endl;
      break;
    }
    f[i] = i;
    for (ll j = i + i; j <= n * 2; j += i)
      if (!f[j]) f[j] = i;
  }
  return 0;
}