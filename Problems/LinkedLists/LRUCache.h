#ifndef LEETCODE_LRUCACHE_H
#define LEETCODE_LRUCACHE_H

#include <unordered_map>

class Node1 {
public:
    int key;
    int val;
    Node1 *prev;
    Node1 *next;

    Node1(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {    //Least Recently Used
private:
    Node1 *head;
    Node1 *tail;
    std::unordered_map<int, Node1 *> cacheMap;
    int maxCapacity;

public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
        head = tail = nullptr;
    }

    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) return -1;

        auto foundNode = it->second;
        if (foundNode != head) {

            if (foundNode == tail) {
                tail = foundNode->prev;
                tail->next = nullptr;
            } else {
                foundNode->prev->next = foundNode->next;
                foundNode->next->prev = foundNode->prev;
            }

            foundNode->next = head;
            head->prev = foundNode;
            foundNode->prev = nullptr;
            head = foundNode;
        }

        return foundNode->val;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {     //if key exists
            cacheMap[key]->val = value;
            get(key);
            return;
        }

        if (cacheMap.size() >= maxCapacity) {       //If capacity is reached, delete the LRU node
            auto oldNode = tail;
            cacheMap.erase(oldNode->key);
            if (head == tail) {
                head = tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
                oldNode->prev = nullptr;
            }
            delete oldNode;
        }

        auto newNode = new Node1(key, value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cacheMap.emplace(key, newNode);
    }
};


#endif //LEETCODE_LRUCACHE_H
