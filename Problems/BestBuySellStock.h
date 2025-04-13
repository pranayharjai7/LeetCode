#ifndef LEETCODE_BESTBUYSELLSTOCK_H
#define LEETCODE_BESTBUYSELLSTOCK_H

#include <vector>

class BestBuySellStock {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit_max = 0;
        int bestBuy = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            profit_max = std::max(profit_max, prices[i] - bestBuy);
            bestBuy = std::min(bestBuy, prices[i]);
        }
        return profit_max;
    }
};


#endif //LEETCODE_BESTBUYSELLSTOCK_H
