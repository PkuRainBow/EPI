//
// implement the big interger multiply operator
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

class BigInt {
private :
    int sign;
    vector<char> digits;
public:
    BigInt(const int &capacity) : sign(1), digits(capacity) {}
    BigInt(const string &s) : sign(s[0] == '-' ? -1 : 1),
                              digits(s.size() - (s[0] == '-')) {
        for (int i = s.size() - 1, j = 0; i >= (s[0] == '-'); --i, ++j) {
            if (isdigit(s[i])) {
                digits[j] = s[i] - '0';
            }
        }
    }

    BigInt operator*(const BigInt &n) const {
        int sum_size = digits.size() + n.digits.size();
        BigInt result(sum_size);
        result.sign = sign * n.sign;
        int i, j;
        for (i = 0; i < n.digits.size(); ++i) {
            if (n.digits[i]) {
                int carry = 0;
                for (j = 0; j < digits.size() || carry; ++j) {
                    int n_digits = result.digits[i + j] +
                            (j < digits.size() ? n.digits[i] * digits[i] : 0) +
                            carry;
                    result.digits[i + j] = n_digits % 10;
                    carry = n_digits / 10;
                }
            }
        }

        if ((digits.size() == 1 && digits.front() == 0) ||
                (n.digits.size() == 1 && n.digits.front() == 0)) {
            result.digits.resize(1);
        } else {
            result.digits.resize(i + j - 1);
        }
        return result;
    }
};