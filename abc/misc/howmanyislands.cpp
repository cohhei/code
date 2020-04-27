#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int c[50][50];
void dfs(int i, int j, int w, int h) {
  c[i][j] = 0;
  rep(k, 3) {
    int di = i - 1 + k;
    if (di < 0 || h <= di) continue;
    rep(l, 3) {
      int dj = j - 1 + l;
      if (dj < 0 || w <= dj) continue;
      if (di == i && dj == j) continue;
      if (c[di][dj]) dfs(di, dj, w, h);
    }
  }
}

int main() {
  vector<int> ans;
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w + h == 0) break;
    // vector<vector<int> > c(w, vector<int>(h));
    rep(i, h) rep(j, w) cin >> c[i][j];
    // cout << endl;
    // rep(i, h) {
    //   rep(j, w) printf("%d ", c[i][j]);
    //   cout << endl;
    // }
    int cnt = 0;
    rep(i, h) rep(j, w) {
      if (c[i][j] == 0) continue;
      cnt++;
      dfs(i, j, w, h);
      // rep(i, h) {
      //   rep(j, w) printf("%d ", c[i][j]);
      //   cout << endl;
      // }
    }
    ans.push_back(cnt);
  }
  for (int a : ans) cout << a << endl;
  return 0;
}