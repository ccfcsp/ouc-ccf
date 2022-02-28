// 201509-2 日期计算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T31

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int months[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
//把每个月的天数记录在数组里面，方便查，第一位舍去，从1开始

int is_leap(int year)
//判断是否是闰年，闰年的二月比普通年份多1天
{
    if (year % 4 == 0 && year % 100 || year % 400 == 0)
        return 1;
    return 0;
}

int get_days(int y, int m)//判断这个月有多少天
{
    int s = months[m];
    if (m == 2) return s + is_leap(y);
    return s;
}

int main()
{
    int year, d;
    cin >> year >> d;//输入年份 year,输入第几天 d
    for (int i = 1; i <= 12; i++)
    //从这一年的第一个月开始往后计算天数
        for (int j = 1; j <= get_days(year, i); j++)
        //每往后查一天，d自减一次
        //直到d自减为0，则查找成功
        {
            if (--d == 0)
            {
                printf("%d\n%d\n", i, j);
                //i表示第几个月，j表示是这个月的第几天
                return 0;
            }
        }

    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
