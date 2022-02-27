// 201409-3 字符串匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//http://118.190.20.162/view.page?gpid=T14

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

string get(string str)
{
    string res;//定义一个空的字符串变量

    for(int i =0 ;i<str.size();i++)
        res += tolower(str[i]);
        //'abc'+'cd' = 'abccd'  +可以把字符连接起来
        //如果是变成大写则为：toupper(str[i])
        //tolower,toupper在C++中包含在#include <iostream>
    return res;
}

int main()
{
    string S;//输入字符串S
    //freopen("test.txt","r",stdin);
    cin >> S;
    int n, type;
    cin >> type >> n;//type表示是否区分大小写，
                    //n表示给出的文字的行数

    while (n--)//在每行文字里面查找

    {
        string str;
        cin >> str;//输入文字
                 // HelloWorld
                //  HiHiHelloHiHi
                // GrepIsAGreatTool
                //  HELLO
                //  HELLOisNOTHello
        if (type && str.find(S) != -1) cout << str << endl;
        //如果type=1则区分大小写，
        // 且在str里面找到了S 则输出S
        else if (!type && get(str).find(get(S)) != -1) cout << str << endl;
        //如果type=0则不区分大小写，使用get(str)和get(S)将str,s都变成小写
        // 且在str里面找到了S 则输出S
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
