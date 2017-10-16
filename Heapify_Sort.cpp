#include<iostream>
#include<stdlib.h>
using namespace std;
void heapify(int a[], int i, int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int max=i;
	if(l<n&&a[l]>a[i])
		max=l;
	if(r<n&&a[r]>a[max])
		max=r;
	if(max!=i)
	{
		swap(a[i],a[max]);
		heapify(a,max,n);
	}
}
void buildHeap(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(a,i,n);
}
void heap_Sort(int a[],int n)
{
	buildHeap(a,n);
	for(int i=n;i>1;i--)
	{
		swap(a[0],a[i-1]);
		heapify(a,0,i-1);
	}
}
main()
{
	int a[20000],n=20000;
	for(int i=0;i<n;i++)
		a[i]=rand() %30000;
	heap_Sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
