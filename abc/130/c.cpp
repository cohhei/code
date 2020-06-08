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
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  double a = (double)w * h / 2;
  int b = (w == x * 2 && h == y * 2) ? 1 : 0;
  printf("%.10lf %d\n", a, b);
  return 0;
}