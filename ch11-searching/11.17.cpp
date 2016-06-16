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

int find_element_appears_once(const vector<int> &A) {
    int ones = 0, twos = 0;
    for (const int& i : A) {
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}
