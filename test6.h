#ifndef TEST6_H
#define TEST6_H
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
class Solution6
{
public:
    int reverse(int x)
    {
        int judge = 0; //0代表正数，1代表负数
        vector<int> reference{2,1,4,7,4,8,3,6,4,8};
        while (1)
        {
            vector<int> result;
            if (x > 0)
            {
                int n = 0;
                int tmp = x;
                while (tmp > 9)
                {
                    tmp = tmp / 10;
                    n++;
                }
                int remainder = 0;
                while (x != 0)
                {
                    remainder = x / pow(10, n);
                    result.push_back(remainder);
                    x = x - pow(10, n) * remainder;
                    n--;
                }
                int num = result.size()-1;
                for (int i = 0; i < result.size()/2;)
                {
                    swap(result[i],result[num]);
                    i++;
                    num--;
                }

                if(result.size()>=10)
                {
                    int i = 0;
                    while(1)
                    {
                        if(result[i] == reference[i]) i++;
                        else if(result[i] > reference[i]) return 0;
                        else { break;}
                        if(i == result.size()-1) break;
                    }
                }
                num = result.size()-1;
                int result_  = 0;
                for(int i = 0; i < result.size(); i++)
                {
                    result_ += result[i]*pow(10,num);
                    num--;
                }
                if (judge == 0 && result_ <= pow(2,31)-1) return result_;
                else if (judge == 1 && -1*result_ >= -1*pow(2,31)) return result_*-1;
                else return 0;
            }
            else if (x < 0 && x > -1*pow(2,31))
            {
                x = -1 * x;
                judge = 1;
            }
            else if(x == -1*pow(2,31)) return 0;
            else {return 0;}
        }
    }
};
#endif