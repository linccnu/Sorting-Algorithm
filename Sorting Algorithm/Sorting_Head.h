#ifndef Sorting_Head_H
#define Sorting_Head_H

#include <iostream>
#include <fstream>
using namespace std;
const int N=10000;     //Numbers of the seeds
const int Range=10000; //the range of the numbers
const int NBucket=1001;// the numbers of the buckets

//*************ѡ������
void Selection_Sort(int *);
void SelectionSort_Test(int *,double &);

//**************ð������
void Bubble_Sort(int *);
void BubbleSort_Test(int *,double &);


//****************��������
void Insert_Sort(int *);
void InsertSort_Test(int *,double &);

//****************ϣ������
void Shell_Sort(int *);
void ShellSort_Test(int *,double &);

//****************�鲢����
void Merge_Sort(int *,int,int);
void Merge(int *,int,int,int);
void MergeSort_Test(int *,double &);

//****************��������
void MaxHeap_Test(int *,double &);
void Heap_Sort(int *);
void Build_Max_Heap(int *);
void Max_Heapify(int *,int);

//**************��������
void QuickSort(int *,int ,int);
int Partition(int *,int ,int);
int RandomInRange(int ,int);
void QuickSort_Test(int *,double &);

//************Ͱ����
typedef struct BNode Node;
void SetBuckets(Node **);
void BucketSort_Test(int *arr,double &ltime);
void Bucket_Sort(int *arr);
void Insert_Buckets(int);
void Print_Buckets(Node **);
Node* InsertSort(Node*,int);




inline void Swap(int &lhs,int &rhs)
{
	int temp;
	temp=lhs;
	lhs=rhs;
	rhs=temp;
}

#endif