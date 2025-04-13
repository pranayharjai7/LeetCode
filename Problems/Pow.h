#ifndef LEETCODE_POW_H
#define LEETCODE_POW_H


#include <iostream>

class Pow {
public:
    double edgeCases(double x, int n) {
        if (n == 0) return 1;
        if (x == 0.0) return 0;
        if (x == 1.0) return 1;
        if (n == 1) return x;
        if (x == -1.0 && n % 2 == 0) return 1;
        if (x == -1.0 && n % 2 != 0) return -1;
        return -0.5;
    }

    double myPow(double x, int n) {
        double edge = edgeCases(x, n);
        if (edge != -0.5) {
            return edge;
        }

        double ans = 1;
        if (n < 0) {
            x = 1/x;
            n *= -1;
        }
        for (int i = 0; i < n; ++i) {
            ans *= x;
        }
        return ans;
    }

    double myPowBinaryExponentiation(double x, int n) {
        double edge = edgeCases(x, n);
        if (edge != -0.5) {
            return edge;
        }

        double ans = 1;
        long binForm = n;
        if (n < 0) {
            x = 1/x;
            binForm *= -1;
        }

        while (binForm > 0) {
            if (binForm%2 == 1) {
                ans = ans * x;
            }
            x = x*x;
            binForm = binForm/2;
        }

        return ans;
    }

    void solution() {
        double x = 3.0;
        int n = 5;
        double pow = myPow(x, n);
        std::cout << x << " to the power of " << n << " is O(n): " << pow << std::endl;
        double pow2 = myPowBinaryExponentiation(x, n);
        std::cout << x << " to the power of " << n << " is O(logn): " << pow2 << std::endl;
    }
};


#endif //LEETCODE_POW_H
