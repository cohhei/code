#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> r[100001];
int ans[100001];

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> h(n);
  rep(i, n) cin >> h[i];
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    r[a].push_back(b);
    r[b].push_back(a);
    ans[i] = -1;
  }

  rep(i, n) {
    ans[i] = 1;
    for (int next : r[i]) {
      if (h[i] <= h[next]) ans[i] = 0;
    }
    // if (ans[i] != -1) continue;
    // queue<int> q;
    // q.push(i);
    // // ans[0] = 0;
    // while (!q.empty()) {
    //   int now = q.front();
    //   q.pop();
    //   ans[now] = 1;
    //   for (int next : r[now]) {
    //     if (h[now] <= h[next]) ans[now] = 0;
    //     // ans[next] = ans[now] + 1;
    //     if (ans[next] == -1) q.push(next);
    //   }
    // }
  }

  int a = 0;
  rep(i, n) {
    // printf("%2d\n", ans[i]);
    if (ans[i] == 1) a++;
  }
  // cout << endl;
  cout << a << endl;
  return 0;
}