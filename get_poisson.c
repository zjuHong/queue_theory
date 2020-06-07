// https://www.cnblogs.com/liam-ji/p/11679026.html
// https://www.cnblogs.com/liam-ji/p/11623024.html
// 生成符合泊松分布的随机数

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double U_Random();
int possion();

int main()
{
　　int p;
　　int i=0;
　　for(i=0;i<20;i++){
　　    p=possion(i);
        printf("%d ",p);
　　}
　　printf("\n");
　　return 0;
}
//输入参数：泊松分布的λ
int possion(int lambda)
{
　　int k=0;
　　long double p=1.0;
　　long double l=exp(-lambda);
　　double u=U_Random();
　　double F=l;
　　while(u>=F)
　　{
　　　　k++;
　　　　l*=(double)lambda/k;
　　　　F+=l;
　　}
　　return k;
}
double U_Random()
{
　　return (double)rand()/RAND_MAX;
}
