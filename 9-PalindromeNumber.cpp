#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int original = x;
        int reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            if (reversed > (INT_MAX - digit) / 10) {
                return false;
            }
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};

int main() {
    Solution solution;
    
    int x1 = 121;
    std::cout << std::boolalpha << solution.isPalindrome(x1) << std::endl; // true

    int x2 = -121;
    std::cout << std::boolalpha << solution.isPalindrome(x2) << std::endl; // false

    int x3 = 10;
    std::cout << std::boolalpha << solution.isPalindrome(x3) << std::endl; // false

    return 0;
}

