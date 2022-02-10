//
// Created by lifenghe on 2022/2/9.
//

#ifndef CLION_TEST17_H
#define CLION_TEST17_H

#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include <algorithm>

using namespace std;

class Solution17 {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> shineUpon = {{'2', "abc"},
                                                {'3', "def"},
                                                {'4', "ghi"},
                                                {'5', "jkl"},
                                                {'6', "mno"},
                                                {'7', "pqrs"},
                                                {'8', "tuv"},
                                                {'9', "wxyz"}};
        vector<string> result(0);
        int n = digits.length();
        if (n == 0) {
            return result;
        } else if (n == 1) {
            int tmp_num = shineUpon[digits[0]].length();
            string tmp_str;
            for (int i = 0; i < tmp_num; i++) {
                tmp_str += shineUpon[digits[0]][i];
                result.push_back(tmp_str);
                tmp_str.clear();
            }
            return result;
        } else {
            //利用回溯算法解决此问题
            string temp;
            backTracking(result, shineUpon, digits, temp, n, 0);
            return result;
        }
    }

    void backTracking(
            vector<string> &result,  // 保存结果的数组
            map<char, string>shineUpon, //映射结构
            string input, // 输入
            string temp,  // 保存中间数据的数组
            int target,   // 终止条件
            int index     // 叶子节点的起始位置
    ) {
        if (index == target) { result.push_back(temp); }
        else {
            for (auto it: shineUpon[input[index]]) { // 单层搜索
                temp.push_back(it); // temp.push_back(nums[i]); visited[i-1] = true;
                backTracking(result, shineUpon, input, temp, target,
                             index + 1); // backTracking(ans, nusm, visited, temp, target, i或i+1)
                temp.pop_back(); // temp.pop_back(nums[i]); visited[i-1] = false;
            }
        }
    }


};

#endif //CLION_TEST17_H
