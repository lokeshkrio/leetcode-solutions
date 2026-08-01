class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx_sum = INT_MIN , sum = 0;
        for (int val : nums){
            sum += val;
            if (mx_sum<sum) mx_sum = sum;

            if (sum < 0) sum =0;
        }
        return mx_sum;

    }
};