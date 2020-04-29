#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int block[102][102];
map<P, int> dist;

const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  int h, w;
  cin >> w >> h;
  rep(i, h) rep(j, w) cin >> block[i + 1][j + 1];

  queue<P> q;
  q.push(P(0, 0));
  int out = 9;
  block[0][0] = out;
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    P now = P(i, j);
    q.pop();
    rep(d, 8) {
      int ni = i + di[d], nj = j + dj[d];
      if (i % 2 == 0) {
        if (d == 2 || d == 7) continue;  // 奇数行は左上と左下をskip
      } else {
        if (d == 0 || d == 5) continue;  // 偶数行は右上と右下をskip
      }
      if (ni < 0 || ni > h + 1 || nj < 0 || nj > w + 1 || block[ni][nj] == out)
        continue;
      if (block[ni][nj] != 0) continue;
      block[ni][nj] = out;
      q.push(P(ni, nj));
    }
  }

  int ans = 0;
  rep(i, h + 2) rep(j, w + 2) {
    if (block[i][j] != 1) continue;
    block[i][j] = 0;
    q.push(P(i, j));
    dist[P(i, j)] = 0;
    while (!q.empty()) {
      int i = q.front().first;
      int j = q.front().second;
      P now = P(i, j);
      q.pop();
      rep(d, 8) {
        int ni = i + di[d], nj = j + dj[d];
        if (i % 2 == 0) {
          if (d == 2 || d == 7) continue;  // 奇数行は左上と左下をskip
        } else {
          if (d == 0 || d == 5) continue;  // 偶数行は右上と右下をskip
        }
        if (ni < 0 || ni > h + 1 || nj < 0 || nj > w + 1 ||
            block[ni][nj] == 0) {
          continue;
        }
        if (block[ni][nj] == out) {
          ans++;
          continue;
        }
        P next = P(ni, nj);
        if (dist[next] > 0) continue;
        dist[next] = dist[now] + 1;
        block[ni][nj] = 0;
        q.push(P(ni, nj));
      }
    }
  }
  cout << ans << endl;
  // rep(i, h + 2) {
  //   rep(j, w + 2) {
  //     if (i % 2 == 0)
  //       printf("%d ", block[i][j]);
  //     else
  //       printf(" %d", block[i][j]);
  //   }
  //   cout << endl;
  // }
  return 0;
}