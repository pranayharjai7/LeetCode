#ifndef LEETCODE_SEARCH_H
#define LEETCODE_SEARCH_H


class Search {
public:
    int linearSearchArray(int unsortedArray[], int size, int searchElement) {
        for (int i = 0; i < size; ++i) {
            if (unsortedArray[i] == searchElement) {
                return i;
            }
        }
        return -1;
    }

    int linearSearchVector(std::vector<int> &nums, int searchElement) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == searchElement) {
                return i;
            }
        }
        return -1;
    }

    int binarySearch(int sortedArray[], int size, int searchElement) {

        int first = 0;
        int last = size - 1;
        while (first <= last) {
            int mid = first+((last-first)/2); // to escape overflow
            if (sortedArray[mid] == searchElement) {
                return mid;
            } else if (sortedArray[mid] > searchElement) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return -1;
    }

    int binarySearchVector(std::vector<int> sortedVec, int searchElement) {
        int first = 0;
        int last = sortedVec.size()-1;
        while (first <= last) {
            int mid = first+((last-first)/2); // to escape overflow
            if (sortedVec.at(mid) == searchElement) {
                return mid;
            } else if (sortedVec.at(mid) > searchElement) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return -1;
    }

    int binarySearchRecursion(int sortedArray[], int size, int searchElement, int first, int last) {
        if (first > last) {
            return -1;
        }
        int mid = first+((last-first)/2); // to escape overflow
        if (sortedArray[mid] == searchElement) {
            return mid;
        } else if (sortedArray[mid] > searchElement) {
            return binarySearchRecursion(sortedArray, size, searchElement, first, mid-1);
        } else {
            return binarySearchRecursion(sortedArray, size, searchElement, mid+1, last);
        }
    }

    int searchInRotatedSortedArray(std::vector<int>& rotatedArray, int target) {
        int first = 0;
        int last = rotatedArray.size() - 1;

        while(first <= last) {
            int mid = first + ((last-first)/2);
            if (rotatedArray[mid] == target) {
                return mid;
            }
            else if (rotatedArray[first] <= rotatedArray[mid]) {
                if ((rotatedArray[first] <= target) && (target < rotatedArray[mid])) {
                    last = mid - 1;
                } else {
                    first = mid + 1;
                }
            } else {
                if ((rotatedArray[mid] < target) && (target <= rotatedArray[last])) {
                    first = mid + 1;
                } else {
                    last = mid - 1;
                }
            }
        }

        return -1;
    }

    void solution() {
        int arr[] = {1,2,3,4,5,6,8,11,453,45,32,48,23,54,56,49,4342};
        int index = linearSearchArray(arr, 17, 56);
        std::cout << "Linear search Array element found at index: " << index << std::endl;

        int arr2[] = {1,2,3,4,5,6,8,11,23,32,45,48,49,54,56,453,4342};
        int index2 = binarySearch(arr2, 17, 56);
        std::cout << "Binary search Array element found at index: " << index2 << std::endl;

        std::vector<int> vec = {1,2,3,4,5,6,8,11,453,45,32,48,23,54,56,49,4342};
        int index3 = linearSearchVector(vec, 56);
        std::cout << "Linear search Vector element found at index: " << index3 << std::endl;

        std::vector<int> vec2 = {1,2,3,4,5,6,8,11,23,32,45,48,49,54,56,453,4342};
        int index4 = binarySearchVector(vec2, 56);
        std::cout << "Binary search Vector element found at index: " << index4 << std::endl;

        int arr3[] = {1,2,3,4,5,6,8,11,23,32,45,48,49,54,56,453,4342};
        int index5 = binarySearchRecursion(arr3, 17, 56, 0, 16);
        std::cout << "Binary search recursive element found at index: " << index5 << std::endl;

        std::vector<int> vec3 = {54,56,453,4342,1,2,3,4,5,6,8,11,23,32,45,48,49};
        int index6 = searchInRotatedSortedArray(vec3, 3);
        std::cout << "Rotated Sorted element found at index: " << index6 << std::endl;
    }
};


#endif //LEETCODE_SEARCH_H
