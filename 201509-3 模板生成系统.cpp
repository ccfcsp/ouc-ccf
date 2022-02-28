// 201509-3 模板生成系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T30
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
//键值对，key-value
int n, m;
vector<string> strs;
//这是一个二维的字符数组
//strs[0] = '<!DOCTYPE html>'
//str[1] = '<html>'
unordered_map<string, string> vars;
//https://blog.csdn.net/batuwuhanpei/article/details/50727227
int main()
{
    cin >> n >> m;
    //模板的行数为n,变量个数为m
    getchar(); 
    // 因为后面输入的是字符串，所以过滤掉第一行的回车
    while (n--)
    //输入n行模板，保存在strs中
    {
        string str;
        getline(cin, str);
        strs.push_back(str);
        //把输入的一整行代码，插入strs后面保存
    }
    while (m--)
    //输入m个变量
    {
        string key, value;
        cin >> key;
        //输入变量的key,比如name，email
        char c;
        //输入变量的value,比如
        //但是要把""过滤掉再保存
        //David Beckham"
        while (c = getchar(), c != '\"');
        while (c = getchar(), c != '\"') value += c;
        //+可以连接一个个字符： 'D'+'a' = 'Da'
        vars[key] = value;//保存value使之与key对应
    }

    for (auto& str : strs)
    //auto自动匹配数据类型，开始遍历strs（一行一行的代码）
    {
        for (int i = 0; i < str.size();)
            if (i + 1 < str.size() && str[i] == '{' && str[i + 1] == '{')
            //找到了{{，此时i指向第一个{
            {
                int j = i + 3;
                //指向括号里面的key
                //{{ email }} str[j]='e'
                string key;
                while (str[j] != ' ' || str[j + 1] != '}' || str[j + 2] != '}')
                //判断右边是否为 }}，若是则查找结束
                    key += str[j++];//一边查，一边保存{{}}里面的key
                cout << vars[key];
                //把key替换为value，若没有与之对应的value则输出为空
                i = j + 3;
                //跳到"mailto:{{ email} }" 中的"，往后遍历输出
            }
            else cout << str[i++];
            //如果没有找到要替换的遍历，直接输出字符
        cout << endl;//遍历输出完成一行代码，换行，继续遍历下一行
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
