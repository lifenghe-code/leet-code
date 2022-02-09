//
// Created by lifenghe on 2022/2/8.
//

#ifndef CLION_TEST16_H
#define CLION_TEST16_H

#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>

using namespace std;

class Solution16 {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        int error = 10000;
        for (int first = 0; first < n; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int second = first + 1;
            int third = n - 1;
            while (second < third) {
                if (nums[first] + nums[second] + nums[third] > target) {
                    if (abs(target - (nums[first] + nums[second] + nums[third])) < error) {
                        error = abs(target - (nums[first] + nums[second] + nums[third]));
                        result = nums[first] + nums[second] + nums[third];
                    } else { ;
                    }
                    while (second < third) {
                        third--;
                        if (nums[third] == nums[third + 1]) {
                            continue;
                        } else break;
                    }
                } else if (nums[first] + nums[second] + nums[third] < target) {
                    if (abs(target - (nums[first] + nums[second] + nums[third])) < error) {
                        error = abs(target - (nums[first] + nums[second] + nums[third]));
                        result = nums[first] + nums[second] + nums[third];
                    } else { ;
                    }
                    while (second < third) {
                        second++;
                        if (nums[second] == nums[second - 1]) {
                            continue;
                        } else break;
                    }
                } else return target;
            }
        }
    }
};

#endif //CLION_TEST16_H
