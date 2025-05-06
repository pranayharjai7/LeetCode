#ifndef LEETCODE_FOURWINNINGHANDS_H
#define LEETCODE_FOURWINNINGHANDS_H

#include <string>
#include <vector>
#include <algorithm>

/*
 * Given 12 tiles, each with a color and a number. Find if 4 winning hands exist.
 * 1 winning hand consists of 3 tiles, and is decided by either all tiles are same
 * (both colour and number) or (color is same but number are consecutive)
 */

struct Tile {
    std::string color;
    int number;
};

class FourWinningHands {
public:

    bool isWinningHand(std::vector<Tile> &hand) {
        if (hand.size() != 3) return false;     //a hand always has 3 tiles

        if (hand[0].color == hand[1].color &&
            hand[1].color == hand[2].color) {   //check if the colors are same
            if (hand[0].number == hand[1].number &&
                hand[1].number == hand[2].number) {
                return true;
            }

            std::vector<int> nums = {hand[0].number, hand[1].number, hand[2].number};
            std::sort(nums.begin(), nums.end());
            if (nums[0] + 1 == nums[1] && nums[1] + 1 == nums[2]) {
                return true;
            }
        }
        return false;
    }

    bool dfs(std::vector<Tile> tiles) {

        for (int i = 0; i < tiles.size(); ++i) {
            for (int j = i + 1; j < tiles.size(); ++j) {
                for (int k = j + 1; k < tiles.size(); ++k) {
                    std::vector<Tile> candidate = {tiles[i], tiles[j], tiles[k]};
                    if (isWinningHand(candidate)) {
                        std::vector<Tile> remaining;
                        for (int t = 0; t < tiles.size(); ++t) {
                            if (t != i && t != j && t != k) {
                                remaining.push_back(tiles[t]);
                            }
                        }

                        if(dfs(remaining)) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    bool areThereFourWinningHands(std::vector<Tile> &tiles) {
        if (tiles.size() != 12) return false;
        return dfs(tiles);
    }
};


#endif //LEETCODE_FOURWINNINGHANDS_H
