class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxAr = 0, lp = 0, rp = height.size() - 1;

        while (lp < rp) {
            int w = rp - lp;
            int ht = min(height[lp], height[rp]);
            mxAr = max(mxAr, w * ht);

            height[lp] < height[rp] ? lp++ : rp--;
        }

        return mxAr;
    }
};