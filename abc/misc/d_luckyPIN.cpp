#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, 1000) {
    char si[4];
    sprintf(si, "%03d", i);
    int k = 0;
    rep(j, n) {
      if (si[k] == s[j]) k++;
    }
    if (k == 3) ans++;
  }
  cout << ans << endl;
  return 0;
}