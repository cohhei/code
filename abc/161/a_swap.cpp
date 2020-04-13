#include <iostream>
using namespace std;
using ll = long long;
using p = pair<int, int>;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
  tmp = a;
  a = c;
  c = tmp;
  cout << a << " " << b << " " << c << endl;
  return 0;
}
