// 201604-2 俄罗斯方块.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T41

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int g[N][N], s[N][N];
int p[4][4];

bool draw(int x, int y)
//i=0,c
{
    memcpy(s, g, sizeof s);
    //把g数值复制给s，g是为了回退设置的
    //板块一直下移动，当碰到底部时（元素值为2）
    //需要往上回退一步
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        //遍历要移动的板块
            if (p[i][j])
            //一直往下移动板块
            {//i=0;j=0,1,2,3
             //i=1,j=0,1,2,3
                int a = x + i, b = y + j;
                s[a][b] ++;
                if (s[a][b] == 2) return true;
            }
    return false;
}

int main()
{
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 10; j++)
            cin >> g[i][j];
    for (int i = 0; i < 10; i++) g[15][i] = 1;
    //把方块底部设置为1,表示底部的边界
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> p[i][j];
    //输入新加入的板块
    int c;
    cin >> c;
    c--;//由于矩阵是从0开始存储的
    for (int i = 0; ; i++)
        if (draw(i, c))
        //开始将板块向下移动
        //如果板块碰到了底部，回退一步
        {
            draw(i - 1, c);
            break;
        }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << s[i][j] << ' ';
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
	0 0 0 0
	0 1 1 1
	0 0 0 1
    0 0 0 0