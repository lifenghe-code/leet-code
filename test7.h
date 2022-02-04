#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//需求分析：首先先略过字符串中的空格，遇到第一个字符时，先判断是不是‘-’，‘+’，或者是数字，除这几种情况外直接返回0
class Solution7
{
public:
    int myAtoi(string s)
    {
        string reference = "2147483648";
        int num = s.length();
        string s_result;
        int result = 0; //存储结果
        int judge = 0;  //判断正负，0代表+，1代表-，2代表省略符号的正数
        int i = 0;

        if (num == 0)
            return 0;

        while (1)
        {
            if (i == num - 1 && !(s[i] >= 48 && s[i] <= 57))
                return 0;
            if (s[i] == ' ')
                i++;
            else
                break;
        }

        if (s[i] == 45)
            judge = 1; //负数
        else if (s[i] == 43)
            judge = 0; //带符号正数
        else if (s[i] >= 48 && s[i] <= 57)
            judge = 2; //无符号正数
        else
            return 0;
        if (judge == 0) //带符号的正数
        {
            i++;
            while (s[i] >= 48 && s[i] <= 57)
            {
                s_result += s[i];
                i++;
            }
        }

        if (judge == 1) //负数
        {
            i++;
            while (s[i] >= 48 && s[i] <= 57)
            {
                s_result += s[i];
                i++;
            }
        }

        if (judge == 2) //无符号正数
        {
            while (s[i] >= 48 && s[i] <= 57)
            {
                s_result += s[i];
                i++;
            }
        }
        
        //去零操作
        string tmp;
        int k = 0;
        for (; k < s_result.length(); k++)
        {
            if (s_result[k] != 48)
                break;
            else
                ;
        }

        for (; k < s_result.length(); k++)
        {
            tmp += s_result[k];
        }

        s_result = tmp;

        num = s_result.length();
        if (num == 10)
        {
            if(s_result == reference)
            {
                if(judge == 1)
                {
                    return -1 * pow(2, 31);
                }
                else if(judge == 2 || judge == 0)
                {
                    return pow(2, 31)-1;
                }
            }

            for (int j = 0; j < 10; j++)
            {
                if (s_result[j] == reference[j])
                    continue;
                else if (s_result[j] < reference[j])
                    break;
                else if (s_result[j] > reference[j])
                {
                    if (judge == 0 || judge == 2)
                        return pow(2, 31) - 1;
                    else if (judge == 1)
                        return -1 * pow(2, 31);
                    else
                        ;
                }
                else
                    ;
            }


        }
        else if (num > 10)
        {
            if (judge == 0 || judge == 2)
                return pow(2, 31) - 1;
            else if (judge == 1)
                return -1 * pow(2, 31);
            else
                ;
        }
        else
            ;
        num = num - 1;
        for (int i = 0; i <= num; i++)
        {
            result += ((int)s_result[i] - 48) * pow(10, num - i);
        }

        if (judge == 0 || judge == 2)
            ;
        else if (judge == 1)
            result =  -1 * result;
        else
            ;
        return result;
    }
};