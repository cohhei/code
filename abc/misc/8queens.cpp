#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

char b[8][8];

int main() {
  rep(i, 8) rep(j, 8) b[i][j] = '.';
  int k;
  cin >> k;
  vector<int> q(8);
  vector<P> init(k);
  rep(i, k) {
    int x, y;
    cin >> x >> y;
    q[x] = y;
    init[i] = P(x, y);
  }

  vector<int> idx(8);
  rep(i, 8) idx[i] = i;
  do {
    bool skip = false;
    rep(i, k) if (idx[init[i].first] != init[i].second) skip = true;
    if (skip) continue;

    // TODO: check

    rep(i, 8) q[i] = idx[i];
  } while (next_permutation(idx.begin(), idx.end()));

  rep(i, 8) {
    rep(j, 8) {
      if (q[i] == j)
        cout << "Q";
      else
        cout << ".";
    }
    cout << endl;
  }
  return 0;
}