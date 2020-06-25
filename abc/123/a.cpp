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
  vector<int> a(5);
  rep(i, 5) cin >> a[i];
  int k;
  cin >> k;
  rep(i, 5) {
    rep(j, 5) {
      if (j <= i) continue;
      if (a[j] - a[i] > k) {
        cout << ":(" << endl;
        return 0;
      }
    }
  }
  cout << "Yay!" << endl;

  return 0;
}