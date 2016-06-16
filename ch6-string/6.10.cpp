//
// apply permutation : every permutation can be expressed as a composition of disjoint cycles
// Created by pianocoder on 16/6/16.
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

template <typename T>
void apply_permutation(vector<int> &perms, vector<T> &A) {
    for (int i = 0; i < A.size(); i ++) {
        /*** loop to find the cycles **/
        if (perms[i] > 0) {
            /** a record the start index **/
            int a = i;
            T temp = A[i];
            do {
                int next_a = perms[a];
                T next_temp = A[next_a];
                A[next_a] = temp;
                /** mark as visited **/
                perms[a] -= perms.size();
                a = next_a, temp = next_temp;
            } while (a != i);
        }
    }
    size_t size = perms.size();
    for_each(perms.begin(), perms.end(), [size](T &x) { x += size; });
}



