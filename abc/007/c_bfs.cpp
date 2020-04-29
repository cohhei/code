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
  int r, c, si, sj, gi, gj;
  cin >> r >> c >> si >> sj >> gi >> gj;
  si--;
  sj--;
  gi--;
  gj--;
  rep(i, r) rep(j, c) {
    cin >> block[i][j];
    dist[i][j] = -1;
  }

  queue<P> q;
  q.push(P(si, sj));
  dist[si][sj] = 0;
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    block[i][j] = '#';
    rep(d, 4) {
      int ni = i + di[d], nj = j + dj[d];
      if (block[ni][nj] == '#') continue;
      if (dist[ni][nj] != -1) continue;
      dist[ni][nj] = dist[i][j] + 1;
      q.push(P(ni, nj));
    }
  }
  cout << dist[gi][gj] << endl;
  return 0;
}