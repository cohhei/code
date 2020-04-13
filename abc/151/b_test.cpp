#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  int sum = 0;
  rep(i, n - 1) {
    int a;
    cin >> a;
    sum += a;
  }
  int goal = m * n;
  int ans = max(0, goal - sum);
  ans = ans > k ? -1 : ans;
  cout << ans << endl;
  return 0;
}