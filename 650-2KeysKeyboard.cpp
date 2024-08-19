#include <iostream>

int minSteps(int n);

int minSteps(int n)
{
  // caso base
  if (n == 1) return 0;

  // par e impar
  int tmp_n = 1, steps = 0;

  for (int i = 2; i < 1000; ++i)
  {
    if (n % i == 0)
    {
      steps += i;
      n /= i;
      --i;
    }
    if (n == 0) break;
  }
  return steps;
}

int main()
{
  int n;
  std::cin >> n;

  std::cout << miniSteps(n) << std::endl;

  return 0;
}
