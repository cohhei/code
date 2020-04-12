#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int bingo[3][3];
  rep(i, 3) cin >> bingo[i][0];
  rep(i, 3) cin >> bingo[i][1];
  rep(i, 3) cin >> bingo[i][2];
  bool open[3][3];
  rep(i, 3)
  {
    rep(j, 3) open[i][j] = false;
  }
  int n;
  cin >> n;
  rep(i, n)
  {
    int b;
    cin >> b;
    rep(j, 3)
    {
      rep(k, 3) if (bingo[j][k] == b) open[j][k] = true;
    }
  }
  rep(i, 3)
  {
    if (open[i][0] && open[i][1] && open[i][2])
    {
      cout << "Yes" << endl;
      return 0;
    }
    if (open[0][i] && open[1][i] && open[2][i])
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (open[0][0] && open[1][1] && open[2][2])
  {
    cout << "Yes" << endl;
    return 0;
  }
  if (open[2][0] && open[1][1] && open[0][2])
  {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}