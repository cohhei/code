#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct unionFind
{
  vector<int> d; // 根： 木のサイズ x -1, それ以外： 親のID
  unionFind(int n = 0) : d(n, -1) {}
  int find(int x)
  {
    if (d[x] < 0)
      return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y)
  {
    // root化しておく
    x = find(x);
    y = find(y);
    if (x == y)
      return false;

    // x を y に unite
    // d[x] のほうが多きい（=サイズが小さい）場合はswap
    if (d[x] > d[y])
      swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d[find(x)]; }
};

int deg[100005];

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  unionFind uf(n);
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    deg[a]++;
    deg[b]++;
    uf.unite(a, b);
  }
  rep(i,k) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    // 他のグループのブロック関係は関係ないので無視
    // 同じグループ内のブロック関係のみ次数としてカウント
    if (uf.same(a, b)) {
      deg[a]++;
      deg[b]++;
    }
  }
  rep(i,n) {
    // グループ全体から自分と直接の友達関係、ブロック関係を引いた数が友達候補
    int ans = uf.size(i) - 1 - deg[i];
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}