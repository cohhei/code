#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 1e5;
bool is_prime[MAX_N];
int sum[MAX_N];
bool calc_prime(int n) {
  int root = sqrt(n);
  for (int i = 2; i <= root; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

bool like(int n) { return is_prime[n] && is_prime[(n + 1) / 2]; }

int main() {
  is_prime[2] = 1;
  for (int i = 3; i < MAX_N; i += 2) is_prime[i] = calc_prime(i);
  printf("like(3): %d, is_prime(3): %d, isPrime(2): %d\n", like(3), is_prime[3],
         is_prime[2]);
  ll cnt = 0;
  for (int i = 1; i <= MAX_N; i += 2) {
    if (like(i)) cnt++;
    sum[i] = cnt;
  }

  int q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    ll ans = sum[r] - sum[l];
    if(like(l)) ans += 1;
    cout << ans << endl;
  }
  return 0;
}