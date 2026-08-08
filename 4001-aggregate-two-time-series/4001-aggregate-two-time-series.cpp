class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        map<int,int> mp;
        for(auto it : series1)mp[it[0]]++;
        for(auto it : series2)mp[it[0]]++;

        int n = series1.size(),m = series2.size();
        int i= 0,j=0;
        vector<vector<int>> ans;
        for(auto it : mp){
            int t = it.first;
            int tot =0;
            if(i<n)tot += series1[i][1];
            if(j<m)tot += series2[j][1];
            ans.push_back({t,tot});

            if(i<n && series1[i][0] ==t){
                i++;
            }
            if(j<m && series2[j][0] ==t){
                j++;
            }
        }
        return ans;
    }
};