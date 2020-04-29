#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int block[61][61];
int dist[61][61];

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  while (1) {
    memset(dist, -1, sizeof(dist));
    int h, w;
    cin >> w >> h;
    if(w + h == 0) break;
    w = w * 2 - 1;
    h = h * 2 - 1;
    rep(i, h) {
      if (i % 2 == 0) {
        rep(j, w) if (j % 2 == 1) cin >> block[i][j];
      } else {
        rep(j, w) if (j % 2 == 0) cin >> block[i][j];
      }
    }

    queue<P> q;
    q.push(P(0, 0));
    dist[0][0] = 1;
    while (!q.empty()) {
      int i = q.front().first;
      int j = q.front().second;
      P now = P(i, j);
      q.pop();
      rep(d, 4) {
        int ni = i + di[d], nj = j + dj[d];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (block[ni][nj] == 1) continue;

        ni = i + di[d] * 2;
        nj = j + dj[d] * 2;
        if (dist[ni][nj] > 0) continue;
        dist[ni][nj] = dist[i][j] + 1;
        q.push(P(ni, nj));
      }
    }
    // rep(i, h) {
    //   rep(j, w) printf("%3d", dist[i][j]);
    //   cout << endl;
    // }
    int ans = max(0, dist[h - 1][w - 1]);
    cout << ans << endl;
  }
  return 0;
}