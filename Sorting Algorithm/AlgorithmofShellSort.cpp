#include "Sorting_Head.h"
#include "InOutPut.h"
#include <ctime>
#include <exception>

void ShellSort_Test(int *arr,double &ltime)
{
	double tstart=clock();
	Shell_Sort(arr);
	double tend=clock();
	ltime=tend-tstart;
	//OutputNumber(arr,N);
}

void Shell_Sort(int *arr)
{
	if(NULL==arr)
		throw exception("Invalid parameters.");
	int ii,increment,flag,temp;
	for(increment=N/2;increment>0;increment/=2)
		for(ii=increment;ii<N;++ii){
			temp=arr[ii];
			flag=ii-increment;
			while(flag>=0 && arr[flag]>temp){
				arr[flag+increment]=arr[flag];
				flag-=increment;
			}
			flag+=increment;
			arr[flag]=temp;
		}
}