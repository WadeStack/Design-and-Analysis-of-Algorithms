#include <iostream.h>
int CommFactor(int m, int n);
void EgyptFraction(int A, int B);

int main( )
{
	int A, B;
	cout<<"请输入真分数的分子：";
	cin>>A;
	cout<<"请输入真分数的分母：";
	cin>>B;
    EgyptFraction(A, B);
	return 0;
}

void EgyptFraction(int A, int B)  
{                      
    int E, R;
    cout<<A<<"/"<<B<<" = ";            //输出真分数A/B
    do
    {
		E = B/A + 1;                    //求真分数A/B包含的最大埃及分数
		cout<<"1/"<<E<<" + ";                //输出1/E
		A = A * E - B;                   //以下两条语句计算A/B - 1/E
		B = B * E;
		R = CommFactor(B, A);        //函数调用，求A和B的最大公约数
		if (R > 1)                      //最大公约数大于1，即A/B可以化简
		{
			A = A/R; B = B/R;             //将A/B化简
		}
	} while (A > 1);                   //当A/B不是埃及分数时执行循环
    cout<<"1/"<<B<<endl;                //输出最后一个埃及分数1/B
    return;                         
}
int CommFactor(int m, int n)
{
   int r = m % n;
   while (r != 0) 
   {
    m = n;
    n = r;
    r = m % n;
   }
   return n;
}
