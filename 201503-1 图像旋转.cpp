#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int q[N][N];

int main()
{
    //scanf("%d%d", &n, &m);
    cin>>n>>m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            //scanf("%d", &q[i][j]);
            cin>>q[i][j];

    for (int i = m - 1; i >= 0; i -- )//从最后一列开始竖着遍历
    {
        for (int j = 0; j < n; j ++ )
            //printf("%d ", q[j][i]);
            cout<<q[j][i]<<" ";
        //puts("");//puts输出一串字符串后，会自动换行，不需要再加一个\n
        cout<<endl;
    }
    return 0;
}
