#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int vec[11][4];
int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<int> idx(n);
  for (int i = 0; i < n; i++) idx[i] = i + 1;

  rep(i, q) rep(j, 4) cin >> vec[i][j];
  ll ans = 0;
  ll lp = pow(10, 7);
  printf("q: %d lp: %d\n", q, lp);
  rep(i, lp) {
    // bool skip = false;
    // vector<int> v(n);
    // rep(j, n) {
    //   v[j] = to_string(i)[j] - '0';
    //   if (v[j] > m || v[j] <= 0) skip = true;
    // }
    // if (skip) continue;
    // rep(j, n) printf("%d", v[j]);
    // cout << endl;
    string v = to_string(i);
    ll sum = 0;
    rep(j, q) {
      // cout << "q" << endl;
      if (v[vec[j][1] - 1] - v[vec[j][0] - 1] == vec[j][2]) sum += vec[j][3];
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
  do {
    rep(i, n) printf("%3d", idx[i]);
    cout << endl;
    rep(i, n) if (idx[vec[i][1] - 1] - idx[vec[i][0] - 1] == idx[vec[i][2] - 1])
        ans += idx[vec[i][3]];
  } while (next_permutation(idx.begin(), idx.end()));
  cout << ans << endl;

  return 0;
}