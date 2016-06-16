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

/** we keep a (2*k-1) size array, we add elements to it utill full, then find the **/
template <typename T>
T find_k_th_largest_unknown_length(istringstream &sin, const int& k) {
    vector<T> M;
    T x;
    while (sin >> x) {
        M.emplace_back(x);
        if (M.size() == (k << 1) - 1) {
            nth_element(M.begin(), M.begin() + k - 1, M.end(), greater<T>());
            M.resize(k);
        }
    }
    nth_element(M.begin(), M.begin() + k - 1, M.end(), greater<T>());
    return M[k - 1];
}


