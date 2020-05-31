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
  rep(i, n) {
    int a;
    cin >> a;
    p[i] = q[i] = a;
  }
  sort(q.begin(), q.end());
  int cnt = 0;
  rep(i, n) {
    if (q[i] != p[i]) cnt++;
  }
  string ans = cnt <= 2 ? "YES" : "NO";
  cout << ans << endl;
  return 0;
}