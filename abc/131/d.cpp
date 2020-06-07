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
  vector<P> tasks(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    tasks[i] = P(b, a);
  }
  sort(tasks.begin(), tasks.end());
  int time = 0;
  for (P t : tasks) {
    int a = t.second, b = t.first;
    if (time + a > b) {
      cout << "No" << endl;
      return 0;
    }
    time += a;
  }
  cout << "Yes" << endl;
  return 0;
}