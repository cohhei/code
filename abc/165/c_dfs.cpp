#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int n;  // length
int m;  // max value
int q;
vector<int> a, b, c, d;
int ans;

// 各桁が1以上m以下のn桁の数列を全列挙
// e.g. 111 112 113 122 123 133 222 223 233 333
void dfs(vector<int> A) {
  if (A.size() == n + 1) {
    rep(i, n) cout << A[i + 1];
    cout << " ";
    int score = 0;
    rep(i, q) if (A[b[i]] - A[a[i]] == c[i]) score += d[i];
    ans = max(ans, score);
    return;
  }

  A.push_back(A.back());
  while (A.back() <= m) {
    dfs(A);
    A.back()++;
  }
}

int main() {
  cin >> n >> m >> q;
  a = b = c = d = vector<int>(q);
  rep(i, q) { cin >> a[i] >> b[i] >> c[i] >> d[i]; }
  dfs(vector<int>(1, 1));
  cout << endl;
  cout << ans << endl;
  return 0;
}