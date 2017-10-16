#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void quick_sort(int a[],int left,int right)
{
	if(left<right)
	{
		int k=(left+right)/2;
		int t=a[k];
		int i=left,j=right;
		do
		{
			while(a[i]<t) i=i+1;
			while(a[j]>t) j=j-1;
			if (j<=j)
			{
				int tg=a[i];
				a[i]=a[j];
				a[j]=tg;
				i=i+1; j=j-1;
			}
		}while(i<=j);
		#pragma omp parallel
		quick_sort(a,left,j);
		quick_sort(a,i,right);
	}
}
main()
{
	int a[20000],n=20000;
	for(int i=0;i<n;i++)
		a[i]=rand() %30000;
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
