#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = INT32_MAX;
const ll INFL = INT64_MAX;
const int mod = 1e9;

template <typename T>
void print_vec(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << endl;
}

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  if (s[0] == s[1] && s[2] == s[3] && s[0] != s[2])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}