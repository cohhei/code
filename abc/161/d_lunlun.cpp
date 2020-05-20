#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int k;
  cin >> k;
  queue<ll> q;
  vector<ll> l;
  rep(i, 9) {
    q.push(i + 1);
    l.push_back(i + 1);
  }
  while (l.size() < k) {
    ll now = q.front();
    q.pop();
    for (int i = -1; i < 2; i++) {
      int n = now % 10 + i;
      if (0 <= n && n <= 9) {
        ll m = now * 10 + n;
        l.push_back(m);
        q.push(m);
      }
    }
  }
  cout << l[k - 1] << endl;
  return 0;
}