
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mx_profit = 0
        
        lp =0
        rp = 1
        
        while(rp < len(prices)):
            #profitable
            if ( prices[rp] > prices[lp]):
                mx_profit = max(mx_profit,prices[rp] - prices[lp])
            else:
                lp=rp
            rp+=1
        return mx_profit
        