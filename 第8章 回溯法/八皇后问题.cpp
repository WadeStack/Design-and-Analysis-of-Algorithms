#include<bits/stdc++.h>
using namespace std;                                  //使用绝对值函数abs
const int N = 100;                                //假定最多求100皇后问题
int x[N] = {-1};               //由于数组下标从0开始，将数组x[N]初始化为-1
void Queue(int n);                                              //函数声明
int Place(int k);                                                //函数声明

//空行，以下是主函数
int main( )
{
    int n;
    cout<<"请输入皇后的个数:";                    //输出提示信息
    cin>>n;                                      //输入皇后的个数
    Queue(n);                                  //函数调用，求解n皇后问题
    return 0;                         //将0返回操作系统，表明程序正常结束
}
//空行，以下是其他函数定义
void Queue(int n)                              //函数定义，求解n皇后问题
{
    int k = 0;                                   //num存储解的个数
    while (k >= 0)                               //摆放皇后k，注意0≤k＜n
    {
        x[k]++;                                       //在下一列摆放皇后k
        while (x[k] < n && Place(k) == 1)                           //发生冲突
            x[k]++;                                       //皇后k试探下一列
        if (x[k] < n && k == n - 1 )                         //得到一个解，输出
        {
            for (int i = 0; i < n; i++)
                cout<<x[i]+1<<"  ";         //数组下标从0开始，打印的列号从1开始
            cout<<endl;
            return;                         //只求出一个解即可
        }
        else if (x[k] < n && k < n - 1)                         //尚有皇后未摆放
            k = k + 1;                               //准备摆放下一个皇后
        else
            x[k--] = -1;                  //重置x[k]，回溯，重新摆放皇后k
    }
    cout<<"无解"<<endl;
}
int Place(int k)                    //考察皇后k放置在x[k]列是否发生冲突
{
    for (int i = 0; i < k; i++)
        if (x[i] == x[k] || abs(i - k) == abs( x[i] - x[k]))             //违反约束条件
            return 1;                                          //冲突，返回1
    return 0;                                            //不冲突，返回0
}
