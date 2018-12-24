#include<bits/stdc++.h>
using namespace std;#include<bits/stdc++.h>
using namespace std;
const int N = 8;                       //假设求解8枚硬币问题
int a[N] = {2, 2,  2, 2, 2,1, 2, 2};
int Coin(int low, int high, int n);

int main()
{
    int i=Coin(0,7,8);
    cout<<"假币是第"<<i<<"个"<<endl;
    return 0;
}//真币的重量是2，假币的重量是1
int Coin(int low, int high, int n)           //在a[low]~a[high]中查找假币
{
    int i, num1, num2, num3;      // num1、num2和num3存储3组硬币的个数
    int add1 = 0, add2 = 0;        //add1和add2存储前两组硬币的重量和
    if (n == 1)                              //递归结束的条件
        return low + 1;                         //返回的是序号，即下标加1
    if (n % 3 == 0)                           //3组硬币的个数相同
        num1 = num2 = n / 3;
    else                                    //前两组有 枚硬币
        num1 = num2 = n / 3 + 1;
    num3 = n - num1 - num2;
    for (i = 0; i < num1; i++)                    //计算第1组硬币的重量和
        add1 = add1 + a[low + i];
    for (i = num1; i < num1 + num2; i++)          //计算第2组硬币的重量和
        add2 = add2 + a[low + i];
    if (add1 < add2)             //在第1组查找，下标范围是low~low+num1-1
        return Coin(low, low + num1 - 1, num1);
    else if (add1 > add2)  //在第2组查找，下标范围low+num1~low+num1+num2-1
        return Coin(low + num1, low + num1 + num2 - 1, num2);
    else                 //在第3组查找，下标范围low+num1+num2~high
        Coin(low + num1 + num2, high, num3);
}
