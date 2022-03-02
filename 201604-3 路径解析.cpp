// 201604-3 路径解析.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T40

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> get(string& str)
//根据'/'分割地址，并保存
//str = '/d2/d3'
{
    vector<string> res;
    for (int i = 0; i < str.size(); i++)
    {//比如/d2/d3
        if (str[i] == '/') continue;
        int j = i + 1;
        while (j < str.size() && str[j] != '/') j++;
        res.push_back(str.substr(i, j - i));
        i = j;
    }
    return res;
    //res = 'd2' 'd3'
    //返回的数据类型是vector
}

void walk(vector<string> cur, vector<string> path)
{//    /d1/./../f1

    for (auto p : path)
    {
        if (p == ".") continue;
        if (p == "..")
        //..表示上一级目录，所以删除最后一个目录，这样就进入到了上一级
        //比如/d2/d3会变成/d2
        {// 'd2'  /
            if (cur.size()) cur.pop_back();
        }
        else cur.push_back(p);
        //  d1 f1
    }

    if (cur.empty())
    //如果cur是空的，说明他代表根目录'/'
    {
        puts("/");
        return;
    }
    for (auto p : cur)
    //如不为空则输出正规化以后的路径
        cout << "/" << p;
    cout << endl;
}

int main()
{
    int n;
    string str;
    cin >> n >> str;
    //str = '/d2/d3'
    vector<string> cur = get(str), ap;
    //vector<string> ap;

    getchar();//过滤换行符
    while (n--)
    {
        getline(cin, str);
        auto path = get(str);
        //把过滤掉'/'的路径元素，保存在path
        if (str.size() && str[0] == '/') walk(ap, path);
        //如果是以/开头，就表示是绝对路径
        else walk(cur, path);
        //   ../d4/f1     /d2
        //   /d2/d4/f1
        //否则就是c输入路径的相对路径
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
