class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(3,0);
        for(int i=n-1;i>=0;i--){
            int x1 = stoneValue[i]-dp[(i+1)%3];
            int x2 = INT_MIN;
            if(i+1<n) x2 = stoneValue[i]+stoneValue[i+1]-dp[(i+2)%3];
            int x3 = INT_MIN;
            if(i+2<n) x3 = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[(i+3)%3];
            dp[i%3] =  max({x1,x2,x3});
        }
        int ans = dp[0];
        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        else return "Tie";
    }
};