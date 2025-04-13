#ifndef LEETCODE_FIBONACCI_H
#define LEETCODE_FIBONACCI_H


#include <iostream>

class Fibonacci {
    int fibonacciRecursiveOptimized(int n, int f1, int f2) {
        int f3 = f1+f2;
        if (n == 2) {
            return f3;
        }
        return fibonacciRecursiveOptimized(n-1, f2, f3);
    }

    int fibonacciRecursive(int n) {
        if (n == 0 || n == 1) return n;
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    }

    int fibonacci(int n) {
        int f1 = 0;
        int f2 = 1;
        int f3 = f1+f2;
        for (int i = 3; i <= n; ++i) {
            f1 = f2;
            f2 = f3;
            f3 = f1+f2;
        }
        return f3;
    }

public:
    void solution() {
        std::cout << "Fibonacci normal: " << fibonacci(10) << std::endl;
        std::cout << "Fibonacci recursive O(2^n): " << fibonacciRecursive(10) << std::endl;
        std::cout << "Fibonacci recursive O(n): " << fibonacciRecursiveOptimized(10, 0, 1) << std::endl;
    }
};


#endif //LEETCODE_FIBONACCI_H
