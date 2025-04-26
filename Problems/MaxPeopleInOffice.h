//
// Created by harjai on 23-Apr-25.
//

#ifndef LEETCODE_MAXPEOPLEINOFFICE_H
#define LEETCODE_MAXPEOPLEINOFFICE_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

struct Event {
    std::string badgeNumber;
    bool isEntry;
};

class MaxPeopleInOffice {
public:
    void maxPeopleInOffice(std::vector<Event> &events) {
        int maxCount = 0;
        int currCount = 0;
        std::unordered_set<std::string> entry;
        std::unordered_set<std::string> exit;

        for (int i = 0; i < events.size(); ++i) {
            if (events[i].isEntry && entry.find(events[i].badgeNumber) == entry.end()) {
                entry.insert(events[i].badgeNumber);
                currCount++;
            } else {
                if (exit.find(events[i].badgeNumber) == exit.end()) {
                    exit.insert(events[i].badgeNumber);
                    currCount--;
                }
            }
            maxCount = std::max(maxCount, currCount);
        }

        std::cout << "Maximum number of people in the office at any time: " << maxCount << std::endl;
    }

    void solution() {
        std::vector<Event> events = {
                {"A123", true},  // Person A enters -> count = 1
                {"B456", true},  // Person B enters -> count = 2
                {"A123", false}, // Person A exits  -> count = 1
                {"C789", true},  // Person C enters -> count = 2
                {"B456", false}, // Person B exits  -> count = 1
                {"C789", false}  // Person C exits  -> count = 0
        };

        maxPeopleInOffice(events);
    }
};


#endif //LEETCODE_MAXPEOPLEINOFFICE_H
