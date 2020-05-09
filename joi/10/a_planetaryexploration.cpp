#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct area {
  int j, o, i;
  void inc(char c) {
    switch (c) {
      case 'J':
        j++;
        break;
      case 'O':
        o++;
        break;
      case 'I':
        i++;
        break;
      default:
        break;
    }
  }
  void add(area a) {
    j += a.j;
    o += a.o;
    i += a.i;
  };
  void sub(area a) {
    j -= a.j;
    o -= a.o;
    i -= a.i;
  };
};
area sum[1001][1001];

const ll mod = 1e5;
int main() {
  int n, m, k;
  cin >> m >> n >> k;
  rep(i, m) rep(j, n) {
    char c;
    cin >> c;
    sum[i][j].inc(c);
    if (i > 0) sum[i][j].add(sum[i - 1][j]);
    if (j > 0) sum[i][j].add(sum[i][j - 1]);
    if (i > 0 && j > 0) sum[i][j].sub(sum[i - 1][j - 1]);
  }

  rep(i, k) {
    int i1, i2, j1, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    i1--;
    j1--;
    i2--;
    j2--;
    area ans = sum[i2][j2];
    if (i1 > 0) ans.sub(sum[i1 - 1][j2]);
    if (j1 > 0) ans.sub(sum[i2][j1 - 1]);
    if (i1 > 0 && j1 > 0) ans.add(sum[i1 - 1][j1 - 1]);
    printf("%d %d %d\n", ans.j, ans.o, ans.i);
  }
  return 0;
}