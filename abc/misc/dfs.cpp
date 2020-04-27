#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int d[100];
int f[100];
int now = 1;
void dfs(vector<vector<int> > v, int i) {
  if (d[i]) return;
  d[i] = now++;
  for (int vv : v[i])
    if (i != vv) dfs(v, vv);
  f[i] = now++;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int> > v(n);
  rep(i, n) {
    int u, k;
    cin >> u >> k;
    vector<int> vv(k);
    rep(j, k) {
      cin >> vv[j];
      vv[j]--;
    }
    v[i] = vv;
  }

  rep(i, n) if (!d[i]) dfs(v, i);
  rep(i, n) { printf("%d %d %d\n", i + 1, d[i], f[i]); }
  return 0;
}