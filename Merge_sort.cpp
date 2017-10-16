#include<iostream>
#include<stdlib.h>
using namespace std;
void swap(int a,int b)
{
	int tam=a;
	a=b;
	b=tam;
}
void merge(int a[],int bt1,int w1,int bt2,int w2,int b[])
{
	int i=bt1;int j=bt2; int bp1=bt1+w1-1; int bp2=bt2+w2-1; int k=bt1;
	while(i<=bp1&&j<=bp2)
	{
		if(a[i]<a[j]) {b[k]=a[i];i++;k++;}
		else {b[k]=a[j];j++;k++;}
	}
	while(i<=bp1)
	{
		b[k]=a[i];i++;k++;
	}
	while(j<=bp2)
	{
		b[k]=a[j];j++;k++;
	}
}
void merge_pass(int a[],int n,int k,int b[])
{
	//1.Khoi tao cac gia tri ban dau
	int cv=n/(2*k);//so cap vet
	int s=2*k*cv;//so pt co do dai k
	int r=n-s;//so pt le cap
	//2.Tron tung cap vet
	for(int j=1;j<=cv;j++)
	{
		int b1=(2*j-2)*k; //bien trai cua vet thu nhat
		merge(a,b1,k,b1+k,k,b);
	}
	//2.Chi con 1 vet
	if(r<=k)
		for(int j=0;j<r;j++)
			b[s+j]=a[s+j];
	//4.Con 2 vet nhung 1 vet co do dai < k
	else
		merge(a,s,k,s+k,r-k,b);
}
void merge_sort(int a[],int n)
{
	//1.Khoi tao so phan tu trong 1 vet
	int k=1;
	//2.Sap xep tron
	int b[n];
	while(k<n)
	{
		//Tron va chuyen cac phan tu vao day b
		merge_pass(a,n,k,b);
		//Tron cac phan tu tro lai day a
		merge_pass(b,n,2*k,a);
		k=k*4;
	}
}
main()
{
	int a[2000];
	int n=2000;
	for(int i=0;i<n;i++)
		a[i]=rand() %40000;
	//int a[8]={1,9,6,4,2,5,8,6};
	//int n=8;
	merge_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
