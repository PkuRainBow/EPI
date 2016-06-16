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

bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0)  return false;
    int n = matrix[0].size();
    /** right up pos **/
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target)  return true;
        else if (matrix[i][j] > target) j--;
        else i++;
    }
    return false;
}