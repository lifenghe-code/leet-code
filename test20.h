//
// Created by lifenghe on 2022/2/12.
//

#ifndef CLION_TEST20_H
#define CLION_TEST20_H

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include <algorithm>

using namespace std;

class Solution20 {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
                {')', '('},
                {']', '['},
                {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};


#endif //CLION_TEST20_H
