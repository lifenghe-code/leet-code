#pragma once
#include <iostream>
#include <string>
using namespace std;
class Solution5
{
public:
    string convert(string s, int numRows)
    {
        int inputLength = s.length();
        char **result = new char *[numRows];
        for (int i = 0; i < numRows; i++)
        {
            result[i] = new char[inputLength]{'?'};
        }
        string result_;
        int mode = 0; // 0代表直线，1代表斜线
        int current = 0;
        int column = 0;
        int line = 0;
        for (; line < numRows;)
        {
            if (mode == 0)
            {
                if (current < inputLength)
                {
                    result[line][column] = s[current];
                    line++;
                    current++;
                }
                else
                    break;
            }
            else if (mode == 1)
            {

                if (current < inputLength)
                {
                    result[line][column] = s[current];
                    line--;
                    column++;
                    current++;
                }
                else
                    break;
            }
            if (line == numRows)
            {
                if(line == 1)
                {
                    mode = 0;
                    line = 0;
                    column++;
                }
                else
                {
                    mode = 1;
                    line -= 2;
                    column++;
                }
            }
            else if (line == -1)
            {
                mode = 0;
                column--;
                line += 2;
            }
        }
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < inputLength; j++)
            {
                if ((result[i][j] >= 65 && result[i][j] <= 90) || (result[i][j] >= 97 && result[i][j] <= 122) || result[i][j] == 46 || result[i][j] == 44)
                {
                    result_ += result[i][j];
                }
                else
                    ;
            }
        }
        return result_;
    }
};