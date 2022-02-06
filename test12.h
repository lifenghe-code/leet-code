//
// Created by lifenghe on 2022/2/5.
//

#ifndef CLION_TEST12_H
#define CLION_TEST12_H

#include <iostream>
#include <vector>

using namespace std;

class Solution12 {
public:
    string intToRoman(int num) {
        int containerInt[13] = {0};
        string result;
        string containerSymbol[] =
                {"M", "CM", "D", "CD", "C", "XC",
                 "L", "XL", "X", "IX", "V", "IV", "I"};
        int containerDivisor[] =
                {1000, 900, 500, 400, 100, 90,
                 50, 40, 10, 9, 5, 4, 1};
        int i = 0;
        while (num != 0) {
            int a = (num / containerDivisor[i]);
            num = num - a * containerDivisor[i];
            while (a != 0) {
                result += containerSymbol[i];
                a--;
            }
            i++;
        }
        return result;
    }

};

#endif //CLION_TEST12_H
