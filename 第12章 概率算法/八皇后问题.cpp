#include<bits/stdc++.h>
using namespace std;
const int N = 100;                                //假定最多求100皇后问题
void Queue(int n);                                              //函数声明
int Place(int x[ ], int k);                                                //函数声明
int Random(int a, int b);
//空行，以下是主函数
int main( )
{
    int n;
    cout<<"请输入皇后的个数:";                    //输出提示信息
    cin>>n;                                      //输入皇后的个数
    srand(time(NULL));
    Queue(n);                                  //函数调用，求解n皇后问题
    return 0;                         //将0返回操作系统，表明程序正常结束
}
//空行，以下是其他函数定义
void Queue(int n)                              //函数定义，求解n皇后问题
{
    int i, j, count = 0;
    int x[1000];
    for (i = 0; i < n; i++)
        x[i] = 0;
    for (i = 0; i < n; )
    {
        j = Random(1, n);
        x[i] = j;
        count++;
        if (!Place(x, i))
        {
            count = 0;
            i++;
        }
        else if (count == n)
        {
            cout<<"本次运行失败"<<endl;
            break;
        }
    }
    for (i = 0; i < n; i++)
        cout<<x[i]<<"  ";
    cout<<endl;
}
int Place(int x[ ], int k)                    //考察皇后k放置在x[k]列是否发生冲突
{
    for (int i = 0; i < k; i++)
        if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))             //违反约束条件
            return 1;                                          //冲突，返回1
    return 0;                                            //不冲突，返回0
}
int Random(int a, int b)
{
    return (rand( )%(b-a) + a);         //rand( )产生[0, 32767]之间的随机整数
}
