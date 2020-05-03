#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> num(n);
  rep(i, k) {
    int d;
    cin >> d;
    rep(j, d) {
      int a;
      cin >> a;
      a--;
      num[a]++;
    }
  }
  int ans = 0;
  rep(j, n) if (num[j] == 0) ans++;
  cout << ans << endl;
  return 0;
}