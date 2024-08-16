#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
  // create a hash map
  unordered_map<int, int> hashMap;

  // set nums size and initialize complement
  int n = nums.size(), complement;

  // go over nums
  for (int i = 0; i < n; ++i)
  {
    // calculate the complement needed to achieve the sum
    complement = target - nums[i];

    // check if the complement is into hashMap -> true => return complement index and i-index
    if (hashMap.count(complement)) return {hashMap[complement], i};

    // add i-index into hashMap's nums[i]-index
    hashMap[nums[i]] = i;
  }

  return {};
}

int main() {
  // example 1
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  // example 2
  // vector<int> nums = {3, 2, 4};
  // int target = 6;
  
  // example 3
  // vector<int> nums = {3, 3};
  // int target = 6;

  // call twoSum function
  vector<int> result = twoSum(nums, target);
  
  // output
  for (int r : result)
  {
    cout << r << " ";
  }

  cout << endl;

  return 0;
}

// run
// g++ -std=c++20 1-TwoSum.cpp -o 1-TwoSum
// ./1-TwoSum
