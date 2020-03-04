#include<stdio.h>//对十个以内的数据进行QGt处理
#include<math.h>
double a[10],s=0,x=0;
int i=0;
void Q();
void G();
void t();
void xs();//计算平均值x和方差s
main()
{
	int k,f;
	double z;
	printf("输入此数据组，输入0时结束输入\n");
	scanf("%d",&k);
	do
	{
		scanf("%lf",a+i);
		i++;
	}
	while(a[i-1]!=0);//当你输入零时，结束输入
	i-=1;
	for(f=i+1;f<10;f++)
	{
		a[f]=0;
	}
	for(f=0;f<i;f++)//对数据组进行排序
	{
		for(k=0;k<i;k++)
	
	{
		if(*(a+k)<*(a+k+1))
		{
			z=a[k];
			a[k]=a[k+1];
			a[k+1]=z;
		}
	}
	}
	printf("输入一个数，用以进行相应的运算\n1:Q检验法\n2:G检验法\n3：t检验法（判断是否有系统误差）\n");
	scanf("%d",&k);
	switch(k)
	{
	case 1:Q();break;
	case 2:xs();G();break;
	case 3:xs();t();break;
	}
	return 0;
}
void Q(int i)//Q检验法
{
	int l=0;
	double q;
	printf("输入表上的Q值后按enter：");
	scanf("%lf",&q);
	if(((a[i-1]-a[i-2])/(a[i-1]-a[0]))>q)
	{
		printf("最大值%lf未通过Q值检测，应舍去\n",a[i-1]);
	}
	if(((a[1]-a[0])/(a[i-1]-a[0]))>q)
	{
		printf("最小值%lf未通过Q值检测，应舍去\n",a[0]);
	}

}
void G(int i)//G检验法
{
	int k;
	double s=0,x=0,g;
	printf("输入表上的g值然后enter：");
	scanf("%lf",&g);
	for(k=0;k<i;k++)
	{
		if(((a[i]-x)/s)>g||((x-a[i])/s)>g)
			printf("此值%lf未通过G检测",a[i]);
	}


}
void xs()//计算平均值x和方差s
{
	int k;
	for(k=0;k<i;k++)
	{
		x+=a[i];
	}
	x=x/i;
	for(k=0;k<i;k++)
	{
		s+=pow((a[i]-x),2);
	}
	s=(s/(i-1));
	s=sqrt(s);
}
void t()//t检验法
{
	double z,t,n;
	printf("输入真值后enter\n");
	scanf("%lf",&z);
	printf("输入t值后enter");
	scanf("%lf",&t);
	n=fabs(x-z)*sqrt(i);
	if((n/s)>t)
		printf("经过t检测后，存在系统误差\n");
	else
		printf("经过t检查后，不存在系统误差\n");
}
