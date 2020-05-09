#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 1e6 + 5;
int cl[MAX_N];

int main() {
  int n;
  cin >> n;
  int mx = 0;

  rep(i, n) {
    int a, b;
    cin >> a >> b;
    mx = max(mx, b + 1);

    if (a >= 0) cl[a]++;
    if (b < MAX_N - 2) cl[b + 1]--;
  }

  rep(i, mx) cl[i + 1] += cl[i];
  int ans = 0;
  rep(i, mx) ans = max(ans, cl[i]);
  cout << ans << endl;
  return 0;
}