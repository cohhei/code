#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

char block[1001][1001];
int dist[10][1001][1001];

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
int main() {
  int h, w, n;
  cin >> h >> w >> n;

  vector<P> factories(n + 1);
  rep(i, h) rep(j, w) {
    char b;
    cin >> b;
    block[i][j] = b;
    rep(k, n) dist[k][i][j] = -1;
    if (b == 'X' || b == '.') continue;
    if (b == 'S')
      factories[0] = P(i, j);
    else
      factories[b - '0'] = P(i, j);
  }

  int ans = 0;
  rep(now, n) {
    queue<P> q;
    P start = factories[now];
    q.push(start);
    dist[now][start.first][start.second] = 0;
    while (!q.empty()) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      rep(d, 4) {
        int ni = i + di[d], nj = j + dj[d];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (block[ni][nj] == 'X') continue;
        if (dist[now][ni][nj] != -1) continue;
        if (P(ni, nj) == factories[now + 1]) {
          ans += dist[now][i][j] + 1;
          q = queue<P>();
          break;
        }
        dist[now][ni][nj] = dist[now][i][j] + 1;
        q.push(P(ni, nj));
      }
    }
  }
  cout << ans << endl;
  return 0;
}