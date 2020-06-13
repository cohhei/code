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
  int a, b;
  cin >> a >> b;
  if (a < 6)
    cout << 0 << endl;
  else if (a < 13)
    cout << b / 2 << endl;
  else
    cout << b << endl;
  return 0;
}