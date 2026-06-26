LEETCODE: 9. Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.
-2^31 <= x <= 2^31 - 1

bool isPalindrome(int x) {
        // Special cases: negative numbers or numbers ending in 0 (except 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;
        while (x > reversedHalf) {
            int rem = x%10;
            reversedHalf = reversedHalf * 10 + rem;
            x /= 10;
        }

        // For even number of digits: x == reversedHalf (12 == 12)
        // For odd number of digits: x == reversedHalf / 10 (1 == 12/10)
        return (x == reversedHalf || x == reversedHalf / 10);
}
