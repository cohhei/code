#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int, vector<int>, less<int> > q;
  rep(i, n) {
    int a;
    cin >> a;
    q.push(a);
  }
  rep(i, m) {
    int t = q.top();
    q.pop();
    t /= 2;
    q.push(t);
  }
  ll ans = 0;
  while (!q.empty()) {
    int t = q.top();
    q.pop();
    ans += t;
  }

  cout << ans << endl;
  return 0;
}