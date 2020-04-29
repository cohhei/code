#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int origin[90][90], block[90][90];
int ans;
int n, m;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

void dfs(int i, int j, int depth) {
  block[i][j] = 0;
  ans = max(ans, depth);
  rep(d, 4) {
    int ni = i + di[d];
    int nj = j + dj[d];
    if (ni < 0 || m <= ni) continue;
    if (nj < 0 || n <= nj) continue;
    if (block[ni][nj]) {
      dfs(ni, nj, depth + 1);
      block[ni][nj] = 1;
    }
  }
}

int main() {
  cin >> n >> m;
  rep(i, m) rep(j, n) cin >> origin[i][j];
  rep(i, m) rep(j, n) {
    memcpy(block, origin, sizeof(origin));
    if (block[i][j]) dfs(i, j, 1);
  }
  cout << ans << endl;
  return 0;
}