#ifndef LEETCODE_STOCKSPANNER_H
#define LEETCODE_STOCKSPANNER_H


#include <vector>
#include <stack>

class StockSpanner {
private:
    std::vector<int> stock;
    std::stack<std::pair<int, int>> stack;
public:
    StockSpanner() {
    }

    int next(int price) {
        int count = 1;
        while (!stack.empty()) {
            if (stack.top().first > price) {
                break;
            }
            count += stack.top().second;
            stack.pop();
        }
        stack.emplace(price, count);
        return count;
    }

    int next2(int price) {
        stock.push_back(price);
        int count = 1;
        int currPrice = stock[stock.size()-1];
        for (int i = stock.size()-2; i >= 0 ; --i) {
            if (stock[i] > currPrice) {
                break;
            }
            count++;
        }

        return count;
    }
};


#endif //LEETCODE_STOCKSPANNER_H
