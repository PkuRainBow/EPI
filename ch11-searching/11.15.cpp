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

int find_missing_element(ifstream &ifs) {
    vector<size_t> counter(1 << 16, 0);
    unsigned int x;
    while (ifs >> x) {
        ++ counter[x >> 16];
    }

    for (int i = 0; i < counter.size(); ++i) {
        /** check the field have missing number **/
        if (counter[i] < (1 << 16)) {
            bitset<(1 << 16)> bit_vec;
            ifs.clear();
            ifs.seekg(0, ios::beg);
            /** record all the missing number by bit **/
            while (ifs >> x) {
                if (i == (x >> 16)) {
                    bit_vec.set(((1<<16) - 1) & x);
                }
            }
            ifs.close();

            for (int j = 0; j < (1 << 16); ++ j) {
                if (bit_vec.test(j) == 0) {
                    return (i << 16) | j;
                }
            }
        }
    }
}