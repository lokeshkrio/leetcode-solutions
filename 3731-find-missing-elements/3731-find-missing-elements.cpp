class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int expected = nums[0];
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] == expected) {
                expected++;
                i++;
            } else if (nums[i] > expected) {
                ans.push_back(expected);
                expected++;
            } else {
                // Skip duplicates
                i++;
            }
        }

        return ans;
    }
};