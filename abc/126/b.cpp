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

bool canBeMonth(int i) { return 1 <= i && i <= 12; }

int main() {
  string s;
  cin >> s;
  int a = atoi(s.substr(0, 2).c_str());
  int b = atoi(s.substr(2, 2).c_str());
  if (canBeMonth(a)) {
    if (canBeMonth(b)) cout << "AMBIGUOUS" << endl;
    else cout << "MMYY" << endl;
  } else {
    if (canBeMonth(b)) cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }
  return 0;
}