//
// Created by pianocoder on 16/6/13.
//


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>


using namespace std;

/** implement the double compare function with the threshold **/
int compare(const double &a, const double &b) {
    double diff = (a - b) / b;
    return diff < -numeric_limits<double>::epsilon() ?
           -1 : diff > numeric_limits<double>::epsilon();
}

double square_root(const double& x) {
    double l, r;
    if (compare(x, 1.0) < 0) {
        l = x, r = 1.0;
    }
    else {
        l =1.0, r = x;
    }
    while (compare(l, r) == -1) {
        double m = l + 0.5 * (r - l);
        double square_m = m * m;
        if (compare(square_m, x) == 0) {
            return m;
        }
        else if (compare(square_m, x) == 1) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return l;
}

//int main() {
//    double test = 2;
//    cout << square_root(test);
//    return 0;
//}

/** implement a function that can divide 2 float number without using / or log or exp **/

/** for the float version, we can follow the similiar patterns to solve the problem**/
int divide (int dividend, int divisor) {
    if (!divisor || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long result = 0;
    long long m = abs((long long)dividend);
    long long n = abs((long long)divisor);
    while (m >= n) {
        long long temp = n, count = 1;
        while( m >= temp << 1) {
            temp <<= 1;
            count <<= 1;
        }
        m -= temp;
        result += count;
    }
    return sign == 1 ? result : - result;
}