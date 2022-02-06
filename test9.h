#pragma once
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution8
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        else if (x > 0)
        {
            vector<int> breakUp;
            int temp = 0;
            int n = 1;
            while(x != 0)
            {
                temp = x%10; //计算出最后一位
                breakUp.push_back(temp);
                x = x - temp;
                x /= 10;
            }
            for(int i = 0,j = breakUp.size()-1; i < j;i++,j--)
            {
                if(breakUp[i] == breakUp[j]) ;
                else return false;
            }
            return true;
        }
    }
};