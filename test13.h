//
// Created by lifenghe on 2022/2/5.
//

#ifndef CLION_TEST13_H
#define CLION_TEST13_H

#include <iostream>
#include <vector>

using namespace std;

class Solution13 {
public:
    int romanToInt(string s) {
        int result = 0;
        const pair<int, char> valueSymbolChar[] = {
                {1000, 'M'},
                {500,  'D'},
                {50,   'L'},
                {5,    'V'}
        };
        auto fun = [=](char x) {  //匿名函数，用于查找，按值捕捉外部变量
            for (int it = 0; it < 4; it++) {
                if (valueSymbolChar[it].second == x)
                    return valueSymbolChar[it].first;
            }
        };
        for (int i = 0; i < s.length();) {
            if (s[i] == 'C') {
                if (i == s.length() - 1) return result + 100;
                i++;
                if (s[i] == 'M') {
                    result += 900;
                    i++;
                } else if (s[i] == 'D') {
                    result += 400;
                    i++;
                } else {
                    result += 100;
                }
            } else if (s[i] == 'X') {
                if (i == s.length() - 1) return result + 10;
                i++;
                if (s[i] == 'C') {
                    result += 90;
                    i++;
                } else if (s[i] == 'L') {
                    result += 40;
                    i++;
                } else {
                    result += 10;
                }
            } else if (s[i] == 'I') {
                if (i == s.length() - 1) return result + 1;
                i++;
                if (s[i] == 'X') {
                    result += 9;
                    i++;
                } else if (s[i] == 'V') {
                    result += 4;
                    i++;
                } else {
                    result += 1;
                }
            } else {
                result += fun(s[i]);
                i++;
            }

        }
        return result;
    }
};

#endif //CLION_TEST13_H
