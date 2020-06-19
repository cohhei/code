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
  double n, k;
  cin >> n >> k;
  vector<int> num(18);
  num[0] = 1;
  rep(i, 17) num[i + 1] = num[i] * 2;
  double ans = 0;
  rep(i, n) {
    int j = i + 1;
    int num_a = lower_bound(num.begin(), num.end(), k / j) - num.begin();
    ans += 1.0 / n * pow(0.5, num_a);
  }
  printf("%.10f\n", ans);
  return 0;
}