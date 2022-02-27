// 201409-2 画图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T15

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;//定义画图的范围，在110x110的范围内画

int n;
bool st[N][N];//定义一个bool类型的数组，记录格子是否被画了，
            //画了则赋值true 1.没画则为false 0

int main()
{
    cin >> n;//要画n个矩形
    while (n--)
    {
        int x1, y1, x2, y2;//矩形的左下角的坐标(x1,y1),
                          // 右上角的坐标（x2,y2）
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++)  
        //画图，按顺序画矩形的小格子
                                        
            for (int j = y1; j < y2; j++)
                st[i][j] = true;      
                //每个格子画完赋值为true
    }
    int res = 0;
    for (int i = 0; i < N; i++)    
    //遍历整个NxN空间，若格子值为true，则计数
        for (int j = 0; j < N; j++)
            res += st[i][j];
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
