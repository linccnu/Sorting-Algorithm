#include "Sorting_Head.h"
#include "InOutPut.h"
#include <ctime>
#include <exception>

int Heap_Size=N;

void MaxHeap_Test(int *arr,double &ltime)
{
	double tstart=clock();
	Heap_Sort(arr);
	double tend=clock();
	ltime=tend-tstart;
	//OutputNumber(arr,N);
}

void Heap_Sort(int *arr)
{
	if(arr==NULL)
		throw exception("Invalid parameters.");
	Build_Max_Heap(arr);
	for(int ii=Heap_Size-1;ii>=1;--ii){
		Swap(arr[0],arr[ii]);
		Heap_Size-=1;
		Max_Heapify(arr,0);
	}
}

void Build_Max_Heap(int *arr)
{
	if(arr==NULL)
		throw exception("Invalid parameters.");
	int lenflag=(Heap_Size>>1)-1;
	for(int ii=lenflag;ii>=0;--ii)
		Max_Heapify(arr,ii);
}

void Max_Heapify(int *arr,int pflag)
{
	int lchildflag=2*pflag+1;
	int rchildflag=2*pflag+2;
	int largestflag;
	if(lchildflag<Heap_Size && arr[lchildflag]>arr[pflag])
		largestflag=lchildflag;
	else
		largestflag=pflag;
	if(rchildflag<Heap_Size && arr[rchildflag]>arr[largestflag])  //!!!这里比较的是右结点和当前最大结点之间的关系 arr[rchildflag]>arr[pflag] 
		largestflag=rchildflag;
	if(largestflag!=pflag){
		Swap(arr[largestflag],arr[pflag]);
		Max_Heapify(arr,largestflag);
	}
}