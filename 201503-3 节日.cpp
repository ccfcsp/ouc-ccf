// 201503-3 节日.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T25

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int months[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};//定义好每个月有多少天，舍弃months[0]

int is_leap(int year)//是否是闰年
{
    if (year % 4 == 0 && year % 100 || year % 400 == 0)
        return 1;
    return 0;
}

int get_days(int year, int month)  // 求某月有多少天
//year= 2015 month = 11
{
    if (month == 2) return months[month] + is_leap(year);
    return months[month];
}

int main()
{
    int a, b, c, y1, y2;//a月的第b周的周c
    cin >> a >> b >> c >> y1 >> y2;
    int days = 0;
    for (int year = 1850; year <= y2; year++)
    //为了方便你推算，已知1850年1月1日是星期二
        for (int month = 1; month <= 12; month++)
        {
            if (year >= y1 && month == a)//月份匹配成功
            {
                int w = (1 + days) % 7, cnt = 0;
                //days表示1850年到上一个最后一天距离的总天数
                //days+1是由于1850年1月1日是是星期二
                //和7取余则w为周日用w=0表示，方便后续判断
                //w表示上个月的最后一天是周几，d从这个月的第一天开始记录
                //cnt记录第几周
                for (int d = 1; d <= get_days(year, month); d++)
                {//月份匹配成功以后，开始从该月的第一天查找，w代表上个月的最后一天是周几
                    if (w == c - 1)//如果c=1,这时候c的前一天就是周日，c-1=0.所以上面用w=0表示周日
                    {
                        cnt++;//周数加1
                        if (cnt == b)//判断周数是否相等，如果相等就说明匹配上了
                        //如果不等，继续往下一个周查找
                        {
                            printf("%04d/%02d/%02d\n", year, month, d);
                            //如果整数不够2位就补上0.比如2会输出02
                            break;
                        }
                    }
                    w = (w + 1) % 7;//星期几也要往后移动一天
                }
                if (cnt < b) puts("none");
            }
            days += get_days(year, month);
            //从1850年到 year年month月的总天数
            //year=y1
            //[1850.1.1-2014.1.31]
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
