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

ll freq[100001];
int main() {
  int n;
  cin >> n;
  ll sum = 0;
  rep(i, n) {
    int a;
    cin >> a;
    sum += a;
    freq[a]++;
  }
  int q;
  cin >> q;
  rep(i, q) {
    int b, c;
    cin >> b >> c;
    sum -= b * freq[b];
    sum += c * freq[b];
    freq[c] += freq[b];
    freq[b] = 0;
    cout << sum << endl;
  }
  return 0;
}