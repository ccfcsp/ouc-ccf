// 201512-2 消除类游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T36

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 33;

int n, m;
int g[N][N];
bool st[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        //双重循环存储矩阵
            cin >> g[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int l = j, r = j, u = i, d = i, x = g[i][j];
            while (l >= 0 && g[i][l] == x) l--;//最左边的坐标（遍历行）
            while (r < m && g[i][r] == x) r++;//最右边的坐标（遍历行）
            while (u >= 0 && g[u][j] == x) u--;//最上边的坐标（遍历列）
            while (d < n && g[d][j] == x) d++;//最下面的坐标（遍历列）
            st[i][j] = r - l - 1 >= 3 || d - u - 1 >= 3;
            //如果这个点左右或者上下连续有三个相同的则标记为1
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (st[i][j]) cout << 0 << ' ';
            else cout << g[i][j] << ' ';
        cout << endl;
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
