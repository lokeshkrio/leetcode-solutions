
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        curr_pay = prices[0]

        for price in prices:
            if price < curr_pay:
                curr_pay = price
            else:
                profit = price - curr_pay
                max_profit = max(max_profit, profit)

        return max_profit