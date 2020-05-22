#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int score = 0;
  rep(i, n - 1) if (s[i] == s[i + 1]) score++;
  int ans = min(n - 1, score + 2 * k);
  cout << ans << endl;
  return 0;
}