#include<bits/stdc++.h>
using namespace std;
double Pi(double e);

int main()
{
    double e, PI;
    cout<<"请输入精度要求：";
    cin>>e;
    PI = Pi(e);
    cout<<"Pi="<<PI<<endl;           //输出π值
    return 0;
}

double Pi(double e)                      //给定近似的精度要求
{
    int i = 6;                           // 从正6边形开始
    double  b, x = 1;                   //2b为正多边形翻倍之前的边长，x为翻被之后的边长
    do
    {
        b = x/2;                        //正6边形的边长为1，即2b=1
        i = i * 2;                      //正多边形的边数翻倍
        x = sqrt(2-2*sqrt(1.0-b*b));         //计算圆内接正多边形翻倍后的边长
    }
    while (i * x - i * b > e);          //精度达到要求则停止计算
    cout<<"圆的内接多边形的边数是："<<i<<endl;
    return (i * x)/2;
}
