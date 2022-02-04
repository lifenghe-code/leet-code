#pragma once
#include <iostream>
#include <string>
using namespace std;
class Solution2
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = 0;
        string result = "";
        int key;
        if (s.length() == 1)
            return 1;
        else
        {
            for (int i = 0; i < s.length(); i++)
            {
                int tmp = 0;
                key = 1;
                for (int j = i; j < s.length(); j++)
                {
                    for (int a = 0; a < tmp; a++)
                    {
                        if (s[j] == result[a])
                        {
                            key = 0;
                            break;
                        }
                        else
                            ;
                        if (a == tmp - 1)
                            key = 1;
                    }
                    if(j == s.length()-1 && key == 1) key = 2;
                    else ;
                    if (key == 1)
                    {
                        result += s[j];
                        tmp++;
                    }
                    else if(key == 0)
                    {
                        if (tmp > len)
                        {
                            len = tmp;
                            break;
                        }
                        else
                            break;
                    }
                    else if(key == 2){
                        result += s[j];
                        tmp++;
                        if (tmp > len)
                        {
                            len = tmp;
                            break;
                        }
                        else
                            break;
                    }
                    else ;
                }
                result = "";
            }
            return len;
        }
    }
};
