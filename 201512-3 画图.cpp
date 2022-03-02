// 201512-3 画图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T35

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m, Q;
char g[N][N];
bool st[N][N];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y, char c)
//填充字符c
{
    st[x][y] = true;
    g[x][y] = c;
    for (int i = 0; i < 4; i++)
    //对一个字符的四周进行填充
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < m && b >= 0 && b < n && !st[a][b])
        {
            if (g[a][b] == '-' || g[a][b] == '|' || g[a][b] == '+') continue;
            //如果相邻的是'-'/'|'/'+'则跳过
            dfs(a, b, c);//如果不是，则深度优先遍历填充
        }
    }
}

int main()
{
    cin >> m >> n >> Q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        //初始情况画布全部是'.'
            g[i][j] = '.';

    while (Q--)
    {//开始根据每条操作画图
        int op;
        cin >> op;
        if (op == 0)
        //op=0表示画线段横着是'-'竖着是'|'
        {
            int x1, y1, x2, y2;//输入两个点的坐标
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            //满足要么x1 = x2 且y1 ≠ y2，要么 y1 = y2 且 x1 ≠ x2。
            //从坐标值较小的点出发开始画
            char c = '-', d = '|';
            //行开始 y1 = y2 x1!=x2
            //列 x1 = x2,y1!=y2
            if (x1 == x2) swap(c, d);
            //如果x坐标相等那就是竖着画'|'
            for (int i = x1; i <= x2; i++)
                for (int j = y1; j <= y2; j++)
                {
                    auto& t = g[i][j];
                    //引用类型，t改变，g[i][j]也随之变
                    //判断之前这个点有没有被d方式画过
                    //如果有则画成'+'
                    if (t == d || t == '+') t = '+';
                    else t = c;//如果没有，直接画
                }
        }
        else
        //如果op=1表示填充
        {
            int x, y;
            char c;
            cin >> x >> y >> c;
            memset(st, 0, sizeof st);
            //初始化st数组都为0
            dfs(x, y, c);//利用深度优先填充
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {//第一个点的坐标为(0,n-1)
        for (int j = 0; j < m; j++)
            cout << g[j][i];
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
