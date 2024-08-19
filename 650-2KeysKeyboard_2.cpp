#include <iostream>

int solve(int n, int k, int val);
int minSteps(int n);

int solve(int n, int k, int val)
{
  if (k >= n) return 0;
  if (n % k == 0) return 2 + solve(n, k + k, k);
  return 1 + solve(n, k + val, val);
}

int minSteps(int n)
{
  return solve(n, 1, 1);
}

int main()
{
  int n;
  std::cin >> n;

  std::cout << minSteps(n) << std::endl;

  return 0;
}
