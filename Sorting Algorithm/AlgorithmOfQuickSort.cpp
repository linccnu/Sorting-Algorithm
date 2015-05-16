//**************************************************************************
#include "Sorting_Head.h"
#include "InOutPut.h"
#include <ctime>
#include <exception>
//using namespace std;

void QuickSort_Test(int *arr,double &ltime)
{
	double tstart=clock();
	QuickSort(arr,0,N-1);
	double tend=clock();
	ltime=tend-tstart;
	//OutputNumber(arr,N);
}
void QuickSort(int *arr,int start,int end)
{
	if(start==end)
		return;
	int index=Partition(arr,start,end);
	if(start<index)
		QuickSort(arr,start,index-1);
	if(index<end)
		QuickSort(arr,index+1,end);
}

int Partition(int *arr,int start,int end)
{
	if(arr==NULL || start<0 ||end>=N)
		throw exception("Invalid Parameters.");
	int index=RandomInRange(start,end);
	Swap(arr[index],arr[end]);

	int flag=start-1;
	for(int ii=start;ii<end;++ii){
		if(arr[ii]<arr[end]){
			++flag;
			if(flag!=ii)
				Swap(arr[flag],arr[ii]);
		}
	}
	++flag;
	Swap(arr[flag],arr[end]);
	return flag;
}

int RandomInRange(int start,int end)
{
	int range,flag;
	range=end-start;
	flag=rand()%range+start;
	return flag;
}