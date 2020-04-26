#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

// binary search 二分探索
int main() {
  int n, q;
  cin >> n;
  vector<int> s(n);
  rep(i, n) cin >> s[i];
  cin >> q;
  vector<int> t(q);
  rep(i, q) cin >> t[i];

  int ans = 0;
  rep(i, q) {
    int st = 0;
    int en = n - 1;

    while (en >= st) {
      int mid = (en + st) / 2;
      if (s[mid] == t[i]) {
        ans++;
        break;
      }
      if (s[mid] > t[i])
        en = mid - 1;
      else
        st = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}