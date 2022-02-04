#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution4
{
public:
    string longestPalindrome(string s)
    {
        string result;
        int length = s.length();
        int head = 0;
        int tail = 0;
        int distance = 0;
        vector<int> theSubscript;
        for (int i = 0; i < length; i++)
        {
            theSubscript.clear();
            int tmp = i;
            for (int j = i+1; j < length; j++)
            {
                if (s[i] == s[j])
                {
                    theSubscript.push_back(j);
                }
            }

            for(auto it = theSubscript.begin();it != theSubscript.end();it++)
            {
                int logo = 0;      //0代表符合条件结束循环，1代表不符合条件中途退出循环
                int a = *it;
                tmp = i;
                while(tmp < a)
                {
                    if(s[tmp] == s[a])
                    {
                        tmp++;
                        a--;
                    }
                    else
                    {
                        logo = 1;
                        break;
                    }
                }
                if(logo == 0)
                {
                    if(distance < (*it)-i+1)
                    {
                        head = i;
                        tail = *it;
                        distance = (*it)-i+1;
                    }
                }
                else
                {

                }
            }

        }
        for(int i = head; i <= tail;i++)
        {
            result += s[i];
        }
        return result;
    }
};