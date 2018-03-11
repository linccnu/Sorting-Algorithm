/*	file:		SortMethods.h
	brief:		Eight sort methods interface
	author:		zhonglin
	date:		2018.3.11
	version:	v1.0.0
 */
#ifndef _SORT_METHODS_H_
#define _SORT_METHODS_H_

#include <iostream>
#include <fstream>
using namespace std;
const int N=10000;     		// Numbers of the seeds
const int Range=10000; 		// the range of the numbers
const int NBucket=1001;		// the numbers of the buckets

/* select sort method */
void SelectionSort(int *pArr);

/* Bubble sort method */
void BubbleSort(int *pArr);

/* Insert sort method */
void InsertSort(int *pArr);

/* Shell sort method */
void ShellSort(int *pArr);

/* Merge sort method */
void Merge_Sort(int *pArr,int,int);
void Merge(int *pArr,int,int,int);
void MergeSort_Test(int *,double &);

/* MaxHeap sort method */
void MaxHeap_Test(int *,double &);
void Heap_Sort(int *pArr);
void Build_Max_Heap(int *pArr);
void Max_Heapify(int *pArr, int);

/* Quick sort method */
void QuickSort(int *pArr, int, int);
int Partition(int *pArr, int, int);
int RandomInRange(int, int);
void QuickSort_Test(int*, double&);

/* Bucket sort method */
typedef struct BNode Node;
void SetBuckets(Node **pNodeData);
void BucketSort_Test(int *pArr, double &ltime);
void Bucket_Sort(int *pArr);
void Insert_Buckets(int);
void Print_Buckets(Node **pNodeData);
Node* InsertSort(Node *pNodeData, int);

/* Swap inline function */
inline void Swap(int *pLeftValue, int *pRightValue)
{
	if(NULL == pLeftValue || NULL == pRightValue)
	{
		printf("param is null\n");
		return;
	}

	int nTmp = *pLeftValue;
	*pLeftValue  = *pRightValue;
	*pRightValue = nTmp;
}

#endif /* end of ifndef */