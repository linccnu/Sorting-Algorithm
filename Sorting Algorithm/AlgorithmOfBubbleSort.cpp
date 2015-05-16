#include "Sorting_Head.h"
#include "InOutPut.h"
#include <ctime>
#include <exception>

void BubbleSort_Test(int *arr,double &ltime)
{
	double tstart=clock();
	Bubble_Sort(arr);
	double tend=clock();
	ltime=tend-tstart;
	//OutputNumber(arr,N);
}

void Bubble_Sort(int *arr)
{
	if(arr==NULL && N<=0)
		return;
	for(int ii=0;ii<N;++ii)
		for(int jj=1;jj<N-ii;++jj)
			if(arr[jj-1]>arr[jj])
				Swap(arr[jj-1],arr[jj]);
}