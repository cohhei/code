#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> to[200001];
vector<int> ans;

void dfs(int i, int x) {
  // (*ans)[i] += x;
  for (int aa : to[i]) {
    if (aa == x) continue;
    ans[aa] += ans[i];
    dfs(aa, i);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  rep(i, n - 1) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }

  ans.resize(n);
  rep(i, q) {
    int p, x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }
  dfs(0, -1);
  for (int a : ans) cout << a << endl;
  return 0;
}