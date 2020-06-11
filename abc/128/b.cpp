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
  map<string, vector<P> > r;
  map<string, int> cities;
  rep(i, n) {
    string s;
    int p;
    cin >> s >> p;
    cities[s] = p;
    r[s].push_back(P(p, i + 1));
  }
  for (auto c : cities) {
    auto list = r[c.first];
    sort(list.rbegin(), list.rend());
    for (P p : list) {
      // cout << p.first << endl;
      cout << p.second << endl;
    }
  }
  return 0;
}