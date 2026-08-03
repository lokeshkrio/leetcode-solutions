class Solution {
public:
    int findSquare(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = findSquare(n);

        while (slow != fast) {
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        }

        return slow == 1;
    }
};