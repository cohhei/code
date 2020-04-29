#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> to[100];
int ans[100];

int main() {
  int n;
  cin >> n;
  rep(i, n) {
    int u, k;
    cin >> u >> k;
    vector<int> v(k);
    rep(j, k) {
      int vj;
      cin >> vj;
      vj--;
      v[j] = vj;
    }
    to[i] = v;
    ans[i] = -1;
  }

  queue<int> q;
  q.push(0);
  ans[0] = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int next : to[now]) {
      if (ans[next] != -1) continue;
      ans[next] = ans[now] + 1;
      q.push(next);
    }
  }

  rep(i, n) printf("%d %d\n", i + 1, ans[i]);

  return 0;
}