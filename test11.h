//
// Created by lifenghe on 2022/2/4.
//

#ifndef CLION_TEST11_H
#define CLION_TEST11_H

#include<iostream>
#include<vector>

using namespace std;

class Solution11 {
public:
    int maxArea(vector<int> &height) {
        int area = 0; //存储面积
        for (int i = 0, j = height.size() - 1; i < j;) {
            if (area < (j - i) * min(height[i], height[j])) {
                area = (j - i) * min(height[i], height[j]);
            } else {
                area = area;
            }
            if (height[i] >= height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return area;
    }
};

#endif //CLION_TEST11_H
