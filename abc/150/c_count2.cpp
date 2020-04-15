#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  vector<int> a(n);
  rep(i, n) a[i] = i + 1;
  map<vector<int>, int> m;
  do {
    m[a] = m.size();
  } while (next_permutation(a.begin(), a.end()));

  int ans = abs(m[p] - m[q]);
  cout << ans << endl;
  return 0;
}