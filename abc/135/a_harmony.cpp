#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;
  if (a < b) swap(a, b);
  int c = a - b;
  if (c % 2 == 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  int ans = b + c / 2;
  cout << ans << endl;
  return 0;
}