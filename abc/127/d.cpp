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

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<P> a;
  rep(i, n) {
    int tmp;
    cin >> tmp;
    a.push(P(tmp, 1));
  }
  rep(i, m) {
    int b, c;
    cin >> b >> c;
    a.push(P(c, b));
  }

  ll ans = 0;
  int i = 0;
  while (1) {
    P p = a.top();
    a.pop();
    int num = min(p.second, n - i);
    ans += (ll)p.first * num;
    i += p.second;
    if (i >= n) break;
  }
  cout << ans << endl;
  return 0;
}