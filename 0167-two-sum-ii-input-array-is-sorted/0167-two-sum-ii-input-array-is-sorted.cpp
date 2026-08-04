class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {


        int lp = 0, rp = numbers.size() - 1;

        while (lp <= rp) {
            int sum = numbers[lp] + numbers[rp];
            if (target == sum) {
               return {lp + 1, rp + 1};
            } else if (target > sum) lp++;
            else rp--;
            
        }
        return {};
    }
};