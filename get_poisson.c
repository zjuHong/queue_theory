// https://www.cnblogs.com/liam-ji/p/11679026.html
// https://www.cnblogs.com/liam-ji/p/11623024.html

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
　　    p=possion();
        printf("%d ",p);
　　}
　　printf("\n");
　　return 0;
}
int possion()
{
　　int lambda=320,k=0;
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
