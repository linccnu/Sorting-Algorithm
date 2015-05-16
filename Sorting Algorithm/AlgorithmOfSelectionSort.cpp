//*****************************************************************************
#include "Sorting_Head.h"
#include "InOutPut.h"
#include <ctime>
#include <exception>

void SelectionSort_Test(int *arr,double &ltime)
{
	double tstart=clock();
	Selection_Sort(arr);
	double tend=clock();
	ltime=tend-tstart;
	//OutputNumber(arr,N);
}

void Selection_Sort(int *arr)
{
	if(arr==NULL)
		return;
	int min;
	for(int ii=0;ii<N;++ii){
		min=ii;
		for(int jj=ii+1;jj<N;++jj){
			if(arr[jj]<arr[min])
				min=jj;
		}
		if(min!=ii)
			Swap(arr[min],arr[ii]);
	}
}