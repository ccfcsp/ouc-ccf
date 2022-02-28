﻿// 201509-1 数列分段.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T32

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int q[N];

int main()
{
    cin >> n;//n，表示数列中整数的个数
    for (int i = 0; i < n; i++) cin >> q[i];
    //输入这个数列
    int res = 1;//第一个数肯定属于一个段
    for (int i = 1; i < n; i++)//从第二个数开始遍历，防止越界
        if (q[i] != q[i - 1])//判断后一个数与前一个数是否相等
                            //不等则数列的段数加1
            res++;
    cout << res << endl;
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
