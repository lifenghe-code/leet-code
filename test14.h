//
// Created by lifenghe on 2022/2/5.
//

#ifndef CLION_TEST14_H
#define CLION_TEST14_H
#include <iostream>
#include <vector>

using namespace std;
class Solution14 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string result;
        auto fun = [&](int x){
            //匿名函数中对外部变量result进行了写操作，故要按引用捕获
            for(int k = 0; k < x; k++){
                result += strs[0][k];
            }
        };
        for(;; i++){  //i,代表字符串中的字符下标

            for(int j = 0; j < strs.size(); j++){ //j，代表容器下标

                if(i >= strs[j].length() || i >= strs[0].length()) {
                    fun(i);
                    return result;
                }
                if(strs[0][i] == strs[j][i]) {
                    continue;
                }
                else {
                    fun(i);
                    return result;
                };
            }

        }
        return result;
    }
};
#endif //CLION_TEST14_H
