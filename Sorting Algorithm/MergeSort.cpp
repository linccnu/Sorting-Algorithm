#include "SortMethods.h"
#include "InOutPut.h"
#include <ctime>
#include <exception>

void MergeSort_Test(int *arr,double &ltime)
{
	double tstart=clock();
	Merge_Sort(arr,0,N-1);
	double tend=clock();
	ltime=tend-tstart;
	//OutputNumber(arr,N);
}

void Merge_Sort(int *arr,int lhs,int rhs)
{
	if(lhs<rhs){
		int median=(lhs+rhs)>>1;
		Merge_Sort(arr,lhs,median);
		Merge_Sort(arr,median+1,rhs);
		Merge(arr,lhs,median,rhs);
	}
}

void Merge(int *arr,int lhs,int meds,int rhs)
{
	int n1=meds-lhs+1;
	int n2=rhs-meds;
	int *arrL=new int[n1];
	int *arrR=new int[n2];
	for(int ii=0;ii<n1;++ii)
		arrL[ii]=arr[lhs+ii];
	for(int jj=0;jj<n2;++jj)
		arrR[jj]=arr[meds+jj+1];
	int ii=0;
	int jj=0;
	int kk=lhs;
	while(ii<n1 && jj<n2){
		if(arrL[ii]>=arrR[jj])
			arr[kk++]=arrR[jj++];
		else
			arr[kk++]=arrL[ii++];
	}		
	while(ii<n1)
		arr[kk++]=arrL[ii++];
	while(jj<n2)
		arr[kk++]=arrR[jj++];
	delete[] arrL,arrR;
}
