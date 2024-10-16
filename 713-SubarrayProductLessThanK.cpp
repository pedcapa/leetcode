class Solution {
/*
713. Subarray Producct Less Than K

- given an array of integers `nums` and an integer `k`
- return the number of contiguos subarrays where the product of all the elements in the subarray
is strictly less than `k`

intuition -> SLIDING WINDOW
*/
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return k;
        int left = 0, right = 0;
        int n = nums.size();
        int mul = 1;
        int ans = 0;
        while (right < n)
        {
            cout << left << ' ' << right << '\n';
            mul *= nums[right];
            while (mul >=k && left <n)
            {
                ans += right - left;
                mul /= nums[left];
                left++;
            }
            right++;
        }

        return ans + (right - left) * (right - left + 1) / 2;
    }
};
