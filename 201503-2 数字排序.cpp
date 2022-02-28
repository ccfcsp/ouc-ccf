// 201503-2 数字排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T26
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int cnt[N];
struct Data
{
    int v, c;//value count
    bool operator< (const Data& t) const
    //单目重载小于号，制定谁排在前面的规则
    //a<b 
    {
        if (c != t.c) return c > t.c;
        //如果数量不等，数量大的放前面
        return v < t.v;
        //如果数目相等，数值小的放前面
    }
}q[N];

int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }

    n = 0;
    for (int i = 0; i < N; i++)
        if (cnt[i])
            q[n++] = { i, cnt[i] };
    sort(q, q + n);
    //sort的结果默认是递增的 q[0]<q[1]<...<q[n-1]
    for (int i = 0; i < n; i++)
        cout << q[i].v << ' ' << q[i].c << endl;

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
