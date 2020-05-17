#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 300;
ll dist[MAX_N][MAX_N];
ll num[MAX_N][MAX_N];
int n, m;

const ll INF = 1e11;
void wf(ll d[MAX_N][MAX_N]) {
  rep(i, n) rep(j, n) rep(k, n) {
    if (d[j][i] != INF && d[i][k] != INF)
      d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
  }
}

int main() {
  int l;
  cin >> n >> m >> l;
  rep(i, n) rep(j, n) {
    if (i != j) {
      dist[i][j] = INF;
      num[i][j] = INF;
    }
  }

  rep(i, m) {
    int s, t, d;
    cin >> s >> t >> d;
    s--;
    t--;
    if (d <= l) {
      dist[s][t] = d;
      dist[t][s] = d;
    }
  }
  wf(dist);
  rep(i, n) rep(j, n) {
    if (dist[i][j] <= l) num[i][j] = 1;
  }
  wf(num);

  int q;
  cin >> q;
  rep(i, q) {
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    if (num[s][t] == INF)
      cout << -1 << endl;
    else
      cout << num[s][t] - 1 << endl;
  }
  return 0;
}