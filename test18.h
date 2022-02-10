//
// Created by lifenghe on 2022/2/10.
//

#ifndef CLION_TEST18_H
#define CLION_TEST18_H

#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
//四数之和
using namespace std;

class Solution18 {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        //第一步先排序
        sort(nums.begin(), nums.end());
        for (int first = 0; first < n; ++first) {
            int second = first + 1;
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            for (int second = first + 1; second < n; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;
                int third = second + 1;
                int four = n-1;
                while(third < four) {
                    double tmp_plus= nums[first] + nums[second]; //防止数据溢出
                    tmp_plus += nums[third] + nums[four];
                    if (tmp_plus == target) {
                        vector<int> temp = {nums[first], nums[second], nums[third], nums[four]};
                        result.push_back(temp);
                        while (third < four) {
                            third++;
                            if (nums[third] == nums[third - 1]) { continue; }
                            else break;
                        }
                        while (third < four) {
                            four--;
                            if (nums[four] == nums[four + 1]) { continue; }
                            else break;
                        }

                    } else if (tmp_plus > target) {
                        while (third < four) {
                            four--;
                            if (nums[four] == nums[four + 1]) { continue; }
                            else break;
                        }
                    } else {
                        while (third < four) {
                            third++;
                            if (nums[third] == nums[third - 1]) { continue; }
                            else break;
                        }
                    }
                }
            }
        }
        return result;
    }
};

#endif //CLION_TEST18_H
