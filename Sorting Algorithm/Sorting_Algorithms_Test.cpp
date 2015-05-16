// Sorting_Algorithms_Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Sorting_Head.h"
#include "InOutPut.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int arr[N]={0};
	//cout<<"The input Numbers are-----------------------"<<endl;
	//OutputNumber(arr,N);
	cout<<"*******************************Begin Sorting!**********************"<<endl;

	InputNumber(arr,N);
	cout<<"<1>BubbleSort begins."<<endl;
	double TimeOfBubbleSort;
	BubbleSort_Test(arr,TimeOfBubbleSort);
	cout<<"Total Sorted-time spending is "<<TimeOfBubbleSort<<"ms"<<endl;

			//FileOutPut(arr,Bubblefile);
			//ofstream fout;
			//fout.open(Bubblefile);
			//for(int ii=0;ii<N;++ii)
			//	fout<<arr[ii]<<'\t';
			//fout.close();
	
	InputNumber(arr,N);
	cout<<endl<<"<2>SelectionSort begins."<<endl;
	double TimeOfSelectionSort;
	SelectionSort_Test(arr,TimeOfSelectionSort);
	cout<<"Total Sorted-time spending is "<<TimeOfSelectionSort<<"ms"<<endl;
	//void FileOutPut(int *arr,const char *SelectionSortFile);

	InputNumber(arr,N);
	cout<<endl<<"<3>InsertSort begins."<<endl;
	double TimeOfInsertSort;
	InsertSort_Test(arr,TimeOfInsertSort);
	cout<<"Total Sorted-time spending is "<<TimeOfInsertSort<<"ms"<<endl;

	InputNumber(arr,N);
	/*cout<<"The input Numbers are-----------------------"<<endl;
	OutputNumber(arr,N);*/
	cout<<endl<<"<4>ShellSort begins."<<endl;
	double TimeOfShellSort;
	ShellSort_Test(arr,TimeOfShellSort);
	cout<<"Total Sorted-time spending is "<<TimeOfShellSort<<"ms"<<endl;

	InputNumber(arr,N);
	cout<<endl<<"<5>MergeSort begins."<<endl;
	double TimeOfMergeSort;
	MergeSort_Test(arr,TimeOfMergeSort);
	cout<<"Total Sorted-time spending is "<<TimeOfMergeSort<<"ms"<<endl;

	InputNumber(arr,N);
	cout<<endl<<"<6>MaxHeapSort begins."<<endl;
	double TimeOfMaxHeapSort;
	MaxHeap_Test(arr,TimeOfMaxHeapSort);
	cout<<"Total Sorted-time spending is "<<TimeOfMaxHeapSort<<"ms"<<endl;

	InputNumber(arr,N);
	cout<<endl<<"<7>QuickSort begins."<<endl;
	double TimeOfQucikSort;
	QuickSort_Test(arr,TimeOfQucikSort);
	cout<<"Total Sorted-time spending is "<<TimeOfQucikSort<<"ms"<<endl;

	InputNumber(arr,N);
	cout<<endl<<"<8>BucketSort begins."<<endl;
	double TimeOfBucketSort;
	BucketSort_Test(arr,TimeOfBucketSort);
	cout<<"Total Sorted-time spending is "<<TimeOfBucketSort<<"ms"<<endl;
	return 0;
}

