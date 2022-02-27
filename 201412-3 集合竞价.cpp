// 201412-3 集合竞价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T19

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;//替换操作，用LL表示long long,简洁
const int N = 5010;

int n=0;//全局变量初始值默认为0
struct Record
{
    int type;//标记是buy还是sell
    double p;//price
    int s;//数量
    bool is_del;//false表示没有cancle
                //true表示cancle了
}d[N];

int main()
{
    string type;
    while (cin >> type)
    {
        if (type == "buy")
        //如果输入字符串是buy标记为1
        {
            double p;
            int s;
            cin >> p >> s;
            d[++n] = { 1, p, s };
            //注意是++n.所以从d[1]开始存储数据
        }
        else if (type == "sell")
        //如果输入字符串是sell标记为2
        {
            double p;
            int s;
            cin >> p >> s;
            d[++n] = { 2, p, s };
        }
        else
        {
            int id;
            cin >> id;
            d[id].is_del = true;//标记id行撤销
            d[++n].is_del = true;//记录cancle这行操作
        }
    }

    double resp;//最终的开盘价
    LL ress = 0;//最终开盘成交量
    for (int i = 1; i <= n; i++)
        if (d[i].is_del == false)
        {
            double p = d[i].p;//每手出价为p
            LL s1 = 0, s2 = 0;//s1记录buy的股数，s2记录sell的股数
            for (int j = 1; j <= n; j++)
                if (d[j].is_del == false)//没有cancle
                    if (d[j].type == 1 && d[j].p >= p) s1 += d[j].s;
                    //如果是buy,并且出价至少为p，则统计该操作的购买股票数目
                    else if (d[j].type == 2 && d[j].p <= p) s2 += d[j].s;
                    //如果是卖,并且出价至多为p，则统计该操作的购买股票数目
            LL t = min(s1, s2);//取buy和sell两种操作之间的最小值
            if (t > ress || (t == ress && p > resp))//&&的优先级高于||，因此先执行&&
                resp = p, ress = t;
                //开盘成交量尽可能地大。如果有多个符合条件的开盘价，你的程序应当输出最高的那一个。
                //t比之前的成交量ress大则将ress更新为t
                //如果成交量相等，输出开盘价最高的
        }
    printf("%.2lf %lld\n", resp, ress);
    //.2表示保留两位小数，double用%lf,long long用%lld
    //float用%f,int用%d
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
