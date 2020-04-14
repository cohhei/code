#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

// BFS 幅優先探索
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  int ans = 0;
  rep(si, h) rep(sj, w) {
    if (s[si][sj] == '#') continue;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<P> q;
    auto update = [&](int i, int j, int x) {
      if (dist[i][j] != -1) return;
      dist[i][j] = x;
      q.push(P(i, j));
      ans = max(ans, x);
    };

    update(si, sj, 0);
    while (q.size()) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      rep(dir, 4) {
        int ni = i + di[dir], nj = j + dj[dir];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        update(ni, nj, dist[i][j] + 1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}