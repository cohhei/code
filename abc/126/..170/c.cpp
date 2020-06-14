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
  int x, n;
  cin >> x >> n;
  map<int, bool> p;
  rep(i, n) {
    int y;
    cin >> y;
    p[y] = true;
  }
  int ans = 0;
  int mn = INF;
  for (int i = 102; i >= 0; i--) {
    if (p[i]) continue;
    if (abs(x - i) <= mn) {
      mn = abs(x - i);
      ans = i;
    }
  }
  std::cout << ans << endl;
  return 0;
}