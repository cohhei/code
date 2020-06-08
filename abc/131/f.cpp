#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = INT32_MAX;
const ll INFL = INT64_MAX;
const int mod = 1e9 + 7;

template <typename T>
void print_vec(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}

const int V = 100005;
vector<int> to[V * 2];
bool visited[V * 2];

vector<int> cnt;
void dfs(int v) {
  if (visited[v]) return;
  visited[v] = true;
  cnt[v / V]++;
  for (int u : to[v]) dfs(u);
}
int main() {
  int n;
  cin >> n;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    y += V;
    to[x].push_back(y);
    to[y].push_back(x);
  }
  ll ans = 0;
  rep(i, V * 2) {
    if (visited[i]) continue;
    cnt = vector<int>(2);
    dfs(i);
    ans += (ll)cnt[0] * cnt[1];
  }
  ans -= n;
  cout << ans << endl;
  return 0;
}