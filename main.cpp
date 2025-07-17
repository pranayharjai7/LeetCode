#include "Problems/TwoSum.h"
#include "Problems/LinkedLists/AddTwoNumbers.h"
#include "Problems/Search.h"
#include "Problems/SingleNumber.h"
#include "Problems/MaximumSubArray.h"
#include "Problems/MajorityElement.h"
#include "Problems/Pow.h"
#include "Problems/WaterContainer.h"
#include "Problems/ProductOfArray.h"
#include "Problems/Fibonacci.h"
#include "Problems/PeakIndexInMountain.h"
#include "Problems/SingleElementInSortedArray.h"
#include "Problems/Sorting.h"
#include "Problems/MergeSortedArray.h"
#include "Problems/NextPermutation.h"
#include "Problems/StringManipulation.h"
#include "Problems/Trees/BinarySearchTree.h"
#include "Problems/Array2D.h"
#include "Problems/FindMissingAndRepeatingValues.h"
#include "Problems/FindDuplicateNumber.h"
#include "Problems/ThreeSum.h"
#include "Problems/SubarraySum.h"
#include "Problems/Subsets.h"
#include "Problems/graphs/Graphs.h"
#include "Problems/graphs/AllPathsGraph.h"
#include "Problems/graphs/RottingOranges.h"
#include "Problems/graphs/NumberOfIslands.h"
#include "Problems/graphs/CyclicDetection.h"
#include "Problems/graphs/TopologicalSort.h"
#include "Problems/graphs/CourseSchedule.h"
#include "Problems/graphs/DijkstraAlgorithm.h"
#include "Problems/graphs/BellmanFordAlgorithm.h"
#include "Problems/graphs/CheapestFlightsWithKStops.h"
#include "Problems/graphs/Practice.h"
#include "Problems/graphs/FloodFill.h"
#include "Problems/graphs/MinimumSpanningTree.h"
#include "Problems/Permutations.h"
#include "Problems/CombinationSum.h"
#include "Problems/PalindromePartitioning.h"
#include "Problems/MergeSort.h"
#include "Problems/QuickSort.h"
#include "Problems/LinkedLists/LinkedList.h"
#include "Problems/graphs/Practice2.h"
#include "Problems/graphs/RatInMaze.h"
#include "Problems/CountInversions.h"
#include "Problems/LinkedLists/DoublyLinkedList.h"
#include "Problems/LinkedLists/CircularLinkedList.h"
#include "Problems/Stacks/Stack.h"
#include "Problems/LinkedLists/LRUCache.h"
#include "Problems/Queues/Queue.h"
#include "Problems/Queues/StackUsingQueues.h"
#include "Problems/Queues/QueueUsingStacks.h"
#include "Problems/Queues/FirstUniqueCharacterInString.h"
#include "Problems/Trees/HeightOfTree.h"
#include "Problems/RelativeRanks.h"
#include "Problems/Trees/ViewsOfTree.h"
#include "Problems/Trees/KthLevelOfTree.h"
#include "Problems/graphs/EventualSafeStates.h"
#include "Problems/ReachTheEnd.h"
#include "Problems/Trees/FindKeysInInterval.h"
#include "Problems/MinimumStrokesOfPaint.h"
#include "Problems/HouseRobber.h"
#include "Problems/graphs/TheMaze.h"
#include "Revision/SearchAndSort.h"
#include "Revision/StringRevision.h"
#include "Revision/VectorRevision.h"

int main() {
    TwoSum twoSum;
    twoSum.solution();

    AddTwoNumbers addTwoNumbers;
    addTwoNumbers.solution();

    Search search;
    search.solution();

    SingleNumber singleNumber;
    singleNumber.solution();

    MaximumSubArray maximumSubArray;
    maximumSubArray.solution();

    MajorityElement majorityElement;
    majorityElement.solution();

    Pow pow1;
    pow1.solution();

    WaterContainer waterContainer;
    waterContainer.solution();

    ProductOfArray productOfArray;
    productOfArray.solution();

    Fibonacci fibonacci;
    fibonacci.solution();

    PeakIndexInMountain peakIndexInMountain;
    peakIndexInMountain.solution();

    SingleElementInSortedArray singleElementInSortedArray;
    singleElementInSortedArray.solution();

    Sorting sorting;
    sorting.solution();

    MergeSortedArray mergeSortedArray;
    mergeSortedArray.solution();

    NextPermutation nextPermutation;
    nextPermutation.solution();

    StringManipulation stringManipulation;
    stringManipulation.solution();

    BinarySearchTree bst;
    bst.solution();

    Array2D array2D;
    array2D.solution();

    FindMissingAndRepeatingValues findMissingAndRepeatingValues;
    findMissingAndRepeatingValues.solution();

    FindDuplicateNumber findDuplicateNumber;
    findDuplicateNumber.solution();

    ThreeSum threeSum;
    threeSum.solution();

    SubarraySum subarraySum;
    subarraySum.solution();

    Subsets subsets;
    subsets.solution();

    Graphs graphs;
    graphs.solution();

    AllPathsGraph allPathsGraph;
    allPathsGraph.solution();

    RottingOranges rottingOranges;
    rottingOranges.solution();

    NumberOfIslands numberOfIslands;
    numberOfIslands.solution();

    CyclicDetection cyclicDetection;
    cyclicDetection.solution();

    TopologicalSort topologicalSort;
    topologicalSort.solution();

    CourseSchedule courseSchedule;
    courseSchedule.solution();

    DijkstraAlgorithm dijkstraAlgorithm;
    dijkstraAlgorithm.solution();

    BellmanFordAlgorithm bellmanFordAlgorithm;
    bellmanFordAlgorithm.solution();

    CheapestFlightsWithKStops cheapestFlightsWithKStops;
    cheapestFlightsWithKStops.solution();

    Practice practice;
    practice.solution();

    FloodFill floodFill;
    floodFill.solution();

    MinimumSpanningTree minimumSpanningTree;
    minimumSpanningTree.solution();

    Permutations permutations;
    permutations.solution();

    CombinationSum combinationSum;
    combinationSum.solution();

    PalindromePartitioning palindromePartitioning;
    palindromePartitioning.solution();

    MergeSort mergeSort;
    mergeSort.solution();

    QuickSort quickSort;
    quickSort.solution();

    LinkedList ll;
    ll.solution();

    BinaryTrees binaryTrees;
    binaryTrees.solution();

    Practice2 practice2;
    practice2.solution();

    RatInMaze ratInMaze;
    ratInMaze.solution();

    CountInversions countInversions;
    countInversions.solution();

    DoublyLinkedList dll;
    dll.solution();

    CircularLinkedList circularLinkedList;
    circularLinkedList.solution();

    Stack stack;
    stack.solution();

    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4

    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << "Queues: \n";
    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }

    StackUsingQueues stackUsingQueues;
    stackUsingQueues.solution();

    QueueUsingStacks queueUsingStacks;
    queueUsingStacks.solution();

    FirstUniqueCharacterInString firstUniqueCharacterInString;
    firstUniqueCharacterInString.solution();

    HeightOfTree heightOfTree;
    heightOfTree.solution();

    RelativeRanks relativeRanks;
    relativeRanks.solution();

    ViewsOfTree viewsOfTree;
    viewsOfTree.solution();

    KthLevelOfTree kthLevelOfTree;
    kthLevelOfTree.solution();

    EventualSafeStates eventualSafeStates;
    eventualSafeStates.solution();

    ReachTheEnd reachTheEnd;
    reachTheEnd.solution();

    FindKeysInInterval findKeysInInterval;
    findKeysInInterval.solution();

    MinimumStrokesOfPaint minimumStrokesOfPaint;
    minimumStrokesOfPaint.solution();

    HouseRobber houseRobber;
    houseRobber.solution();

    TheMaze theMaze;
    theMaze.solution();

    VectorRevision vectorRevision;
    vectorRevision.solution();

    StringRevision stringRevision;
    stringRevision.solution();

    SearchAndSort searchAndSort;
    searchAndSort.solution();    return 0;
}