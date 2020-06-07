// https://www.cnblogs.com/liam-ji/p/11679026.html
https://www.cnblogs.com/liam-ji/p/11623024.html

#include "math.h"

/************************************
	a		---给定区间下限
	b		---给定区间上限
	seed	---随机数种子
************************************/
double uniform(double a, double b, long int *seed)
{
	double t;
	*seed = 2045 * (*seed) + 1;
	*seed = *seed - (*seed / 1048576);
	t = (*seed) / 1048576.0;
	t = a + (b - a) * t;
	return(t);
}

/************************************
	lambda  ---泊松分布均值lambda
	s       ---随机数种子
************************************/
int poisson(double lambda, long int *s)
{
	int i;
	int x;
	double a;
	double b;
	double u;

	a = exp(-lambda);
	i = 0;
	b = 1.0;
	do{
		u = uniform(0.0, 1.0, s);
		b *= u;
		i++;
	}while(b >= a);
	x = i - 1;
	return(x);
}
