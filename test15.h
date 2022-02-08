//
// Created by lifenghe on 2022/2/6.
//

#ifndef CLION_TEST15_H
#define CLION_TEST15_H

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result(0);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3) return result;
        int first = 0;
        for (; first < n - 1; ++first) {
            int third = n - 1;
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            for (int second = first + 1; second < n; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while (second < third && nums[first] + nums[second] + nums[third] > 0) {
                    --third;
                }
                if (second >= third) {
                    break;
                }
                if (nums[first] + nums[second] + nums[third] == 0) {
                    vector<int> tmp = {nums[first], nums[second], nums[third]};
                    result.push_back(tmp);
                }


            }
        }
        return result;
    }

};

#endif //CLION_TEST15_H
