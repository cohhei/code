#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  rep(i, n) {
    int a;
    cin >> a;
    a--;
    if (a == cnt) cnt++;
  }
  int ans = cnt == 0 ? -1 : n - cnt;
  cout << ans << endl;
  return 0;
}