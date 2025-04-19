#ifndef LEETCODE_GASSTATION_H
#define LEETCODE_GASSTATION_H


#include <vector>

class GasStation {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int totalFuel = 0;
        int totalCost = 0;

        //unique solution always exists
        int startIdx = 0;
        int tank = 0;
        for (int i = 0; i < gas.size(); ++i) {
            //totalling the fuel and cost to check at the end if a unique solution exists..
            totalFuel += gas[i];
            totalCost += cost[i];

            //if a unique solution exist
            tank = tank + gas[i] - cost[i];
            if (tank < 0) {
                startIdx = i+1;
                tank = 0;
            }
        }

        if (totalFuel < totalCost) {    //this means no solutions exists
            return -1;
        }

        return startIdx;
    }
};


#endif //LEETCODE_GASSTATION_H
