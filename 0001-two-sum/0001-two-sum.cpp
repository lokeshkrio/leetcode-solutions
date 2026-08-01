class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> match;
        for (int i = 0 ; i<nums.size() ; i++)
        {
            int compliment = target - nums[i];
            if (match.find(compliment) != match.end()) return {match[compliment] , i};
            match[nums[i]] = i;
        }
        return {};
        
    }
};