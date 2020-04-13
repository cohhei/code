#include <iostream>
#include <vector>
#include <cstdlib> // abs() for integer
#include <cmath>
#include <string> // std::string, std::to_string

using namespace std;
using ll = long long;
using p = pair<int, int>;

int main()
{
  int k;
  cin >> k;
  int num = 0;
  vector<ll> l(k);
  for (ll i = 0; i < 10000; i++)
  {
    string str = to_string(i);
    for (int j = 0; j < str.size() - 1; j++)
    {
      cout << (unsigned char)str[j] << endl;
      cout << (unsigned char)str[j+1] << endl;
      if (abs((unsigned char)str[j] - (unsigned char)str[j + 1]) > 1)
      {
        break;
      }
      l[num++] = i;
    }

    // if (i < 10)
    // {
    //   l[num++] = i;
    // }
    // else //if (abs(i / 10 - i % 10) <= 1)
    // {
    //   ll tmp = i;
    //   for (int j = 5; j < 0; j--)
    //   {
    //     tmp = tmp / pow(10, j);
    //     if (abs(i / pow(10, j) - tmp / pow(10, j - 1)) <= 1)
    //     {
    //       l[num++] = i;
    //     }
    //   }
    // }
    if (num - 1 == k)
    {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
