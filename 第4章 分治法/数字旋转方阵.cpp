#include<bits/stdc++.h>
using namespace std;
int data[100][100];
void Full(int number, int begin, int size);

int main()
{
    int size;
    cout<<"输入方阵的大小：";
    cin>>size;
    Full(1,0,size);
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            cout<<data[i][j]<<setw(4);
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
void Full(int number, int begin, int size)
{
    //从number 开始填写size 阶方阵，左上角的下标为(begin, begin)
    int i, j, k;
    if (size == 0)             //递归的边界条件，如果size等于0，则无须填写
        return;
    if (size == 1)                         //递归的边界条件，如果size等于1
    {
        data[begin][begin] = number;         //则只须填写number
        return;
    }
    i = begin;
    j = begin;                   //初始化左上角下标
    for (k = 0; k < size - 1; k++)            //填写区域A，共填写size - 1个数
    {
        data[i][j] = number;                 //在当前位置填写number
        number++;
        i++;                    //行下标加1
    }
    for (k = 0; k < size - 1; k++)            //填写区域B，共填写size - 1个数
    {
        data[i][j] = number;                 //在当前位置填写number
        number++;
        j++;                    //列下标加1
    }
    for (k = 0; k < size - 1; k++)            //填写区域C，共填写size - 1个数
    {
        data[i][j] = number;                //在当前位置填写number
        number++;
        i--;                    //行下标减1
    }
    for (k = 0; k < size - 1; k++)            //填写区域D，共填写size - 1个数
    {
        data[i][j] = number;                //在当前位置填写number
        number++;
        j--;                    //列下标减1
    }
    Full(number, begin + 1, size - 2);       //递归求解，左上角下标为begin + 1
}
