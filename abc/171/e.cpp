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
  int n;
  cin >> n;
  vector<int> a(n);
  int x = 0;
  rep(i, n) {
    cin >> a[i];
    x ^= a[i];
  }
  vector<int> b(n);
  rep(i, n) b[i] = x ^ a[i];
  print_vec(b);
  return 0;
}