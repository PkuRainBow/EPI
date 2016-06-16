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

int close_search(const vector<int> &A, const int &k) {
    int index = 0;
    while (index < A.size() && A[index] != k) {
        index += abs(A[index] - k);
    }
    return index < A.size() ? index : -1;
}