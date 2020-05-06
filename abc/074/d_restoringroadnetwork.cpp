#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e11;
const int MAX_V = 300;

int V;

ll c[MAX_V][MAX_V];
bool enabled[MAX_V][MAX_V];

void wf() {
  rep(i, V) rep(j, V) rep(k, V) {
    if (i == j || j == k || i == k) continue;
    // if (i == 0 && j == 2 && k == 1)
    if (c[i][k] + c[k][j] < c[i][j]) {
      cout << -1 << endl;
      exit(0);
    }
    if (c[i][k] + c[k][j] == c[i][j]) {
      enabled[i][j] = true;
    }
  }
}

int main() {
  cin >> V;
  rep(i, V) rep(j, V) {
    int a;
    cin >> a;
    c[i][j] = a;
  }
  wf();
  ll ans = 0;
  rep(i, V) {
    for (int j = i; j < V; j++) {
      if (!enabled[i][j]) ans += c[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}