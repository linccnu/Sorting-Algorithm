#include "Sorting_Head.h"
#include "InOutPut.h"
#include <ctime>
#include <exception>

void InsertSort_Test(int *arr,double &ltime)
{
	double tstart=clock();
	Insert_Sort(arr);
	double tend=clock();
	ltime=tend-tstart;
	//OutputNumber(arr,N);
}
void Insert_Sort(int *arr)
{
	if(arr==NULL && N<=0)
		return;
	int flag,temp;
	for(int ii=1;ii<N;++ii){
		flag=ii-1;
		temp=arr[ii];
		while(flag>=0 && arr[flag]>temp){
			arr[flag+1]=arr[flag];
			flag--;
		}
		arr[flag+1]=temp;
	}
}
