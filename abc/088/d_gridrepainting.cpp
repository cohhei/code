#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

char block[50][50];
int dist[50][50];

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  int white = 0;
  rep(i, h) rep(j, w) {
    cin >> block[i][j];
    if (block[i][j] == '.') white++;
    dist[i][j] = -1;
  }

  queue<P> q;
  q.push(P(0, 0));
  dist[0][0] = 1;
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    rep(d, 4) {
      int ni = i + di[d], nj = j + dj[d];
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
      if (block[ni][nj] == '#') continue;
      if (dist[ni][nj] != -1) continue;
      dist[ni][nj] = dist[i][j] + 1;
      q.push(P(ni, nj));
    }
  }
  if (dist[h - 1][w - 1] == -1) {
    cout << -1 << endl;
    return 0;
  }
  int ans = white - dist[h - 1][w - 1];
  cout << ans << endl;
  return 0;
}