 class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reversedNum = 0;
        while (x > reversedNum) {
            int lastDigit = x % 10;
            reversedNum = reversedNum * 10 + lastDigit;
            x /= 10;
        }
        return x == reversedNum || x == reversedNum / 10;
    }
};