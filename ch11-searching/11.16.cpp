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
#include <fstream>
#include <iostream>

using namespace std;

/** this approach can cause overflow error **/
pair<int, int> find_duplicate_missing_one_pass(const vector<int>& A) {
    int sum = 0, square_sum = 0;
    for (int i = 0; i < A.size(); i ++) {
        sum += i - A[i];
        square_sum += i * i - A[i] * A[i];
    }
    return {(square_sum / sum - sum) >> 1, (square_sum / sum + sum) >> 1};
};

pair<int, int> find_duplicate_missing(const vector<int> &A) {
    int miss_XOR_dup = 0;
    /** get the m^t value **/
    for (int i = 0; i < A.size(); i ++) {
        miss_XOR_dup ^= i ^ A[i];
    }
    /** as the m and t are different , so we can get at least one different bit **/
    int diff_bit = miss_XOR_dup & (~(miss_XOR_dup - 1));
    int miss_or_dup = 0;
    for (int i = 0; i < A.size(); ++ i) {
        if (i & diff_bit) {
            miss_or_dup ^= i;
        }
        if (A[i] & diff_bit) {
            miss_or_dup ^= A[i];
        }
    }
    /** the diff bit can seperate all the number into one part contains m or t, the remained not **/
    for (const int &A_i : A) {
        if (A_i == miss_or_dup) {
            return {miss_or_dup, miss_or_dup ^ miss_XOR_dup};
        }
    }
    return {miss_or_dup ^ miss_XOR_dup, miss_or_dup};
};