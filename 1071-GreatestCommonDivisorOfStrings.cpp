#include <iostream>
#include <string>
#include <numeric>

using namespace std;

class Solution{
  public:
    string gcdOfStrings(string str1, string str2)
    {
      if (str1 + str2 == str2 + str1)
      {
        return str1.substr(0, gcd(str1.size(), str2.size()));
      }

      return "";
    }
};

int main()
{
  string str1;
  string str2;

  Solution solution;

  cin >> str1;
  cin >> str2;

  cout << solution.gcdOfStrings(str1, str2) << endl;

  return 0;
}
