// Sort_Test.cpp : 各种排序算法
//	1.插入排序
//	2.冒泡排序
//  3.改进的冒泡法
//	4.归并排序

#include "stdafx.h"
#include <iostream>
#include <exception>

using namespace std;

void Insertion_Sort(int arr[],int len);//插入排序算法声明部分

void Buble_Sort1(int arr[],int len);//粗陋冒泡排序算法声明部分

void Buble_Sort2(int arr[],int len);//冒泡排序算法声明部分

void Buble_Sort3(int arr[],int len);//改进冒泡排序算法声明部分

void Merge_Sort(int arr[],int p,int r);//归并递推声明部分
void Merge(int arr[],int p,int q,int r);

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[]={3,1,12,7,2,5,4,3,4,4,1,39,10};
	int len=0;
	len=sizeof(arr)/sizeof(*arr);
	cout<<"The length is "<<len<<endl;
	cout<<"The original array is :"<<endl;
	int ii=0;
	for(ii=0;ii<len;++ii)
		cout<<arr[ii]<<" ";
	cout<<endl;
	cout<<endl<<"Sorting Begins."<<endl;
	Insertion_Sort(arr,len);
	cout<<"The Insertion_Sorted array is :"<<endl;
	for(ii=0;ii<len;++ii)
		cout<<arr[ii]<<" ";
	cout<<endl;

	Buble_Sort1(arr,len);
	cout<<endl<<"The Buble_Sorted array is :"<<endl;
	for(ii=0;ii<len;++ii)
		cout<<arr[ii]<<" ";
	cout<<endl;

	Buble_Sort2(arr,len);
	cout<<endl<<"The Buble_Sorted array is :"<<endl;
	for(ii=0;ii<len;++ii)
		cout<<arr[ii]<<" ";
	cout<<endl;

	Buble_Sort3(arr,len);
	cout<<endl<<"The Buble_Sorted array is :"<<endl;
	for(ii=0;ii<len;++ii)
		cout<<arr[ii]<<" ";
	cout<<endl;

	Merge_Sort(arr,0,len-1);
	cout<<endl<<"The Merge_Sorted array is :"<<endl;
	for(ii=0;ii<len;++ii)
		cout<<arr[ii]<<" ";
	cout<<endl<<"Done!"<<endl;
	return 0;
}

/* **********************
      插入排序算法 
基本思想：将一个记录插入到已经排好序的有序表中，从而得到
一个新的、记录增1的有序表  PS:时间复杂度也是O(n^2) 
************************/
void Insertion_Sort(int arr[],int len)
{// 插入排序法
	if(arr==NULL || len<=0)
		throw exception("Invalid Parameters");
	int temp=0;
	int flag=0;
	for(int ii=1;ii<len;ii++){
		temp=arr[ii];
		for(flag=ii;flag>0 && arr[flag-1]>temp;flag--)
			arr[flag]=arr[flag-1];
		arr[flag]=temp;
	}//end for
}


/* *****************************************
        粗陋冒泡排序算法 
从小到大排列 设置倒数第ii个为哨兵，采用沉底法，基本思想是：
(1)最后一个与第一个比较，如果小于则互换；否则，不动。
(2)最后一个再与第二个比较，如果小于则互换；否则，不动。
...这样一直下去，一次循环下来，最大数值的点肯定在最后。
*******************************************/
void Buble_Sort1(int arr[],int len)
{// 粗陋的冒泡法 
	if(arr==NULL || len<=0){
		cerr<<"Invalid Parameters"<<endl;
		return;
	}//end if
	int temp;
	for(int ii=len-1;ii>0;--ii)
	for(int jj=0;jj<ii;++jj){
		if(arr[jj]>arr[ii]){
			temp=arr[ii];
			arr[ii]=arr[jj];
			arr[jj]=temp;
		}//end for
	}//end for
}

/* *****************************************
              冒泡算法 
从小到大排列 设置倒数第ii个为哨兵，采用沉底法，基本思想是：
(1)第一个与第二个比较，如果大于则互换；否则，不动。
(2)第二个再与第三个比较，如果小于则互换；否则，不动。
...这样一直下去，一次循环下来，最大数值的点肯定在最后。
********************************************/
void Buble_Sort2(int arr[],int len)
{// 冒泡算法  
	if(arr==NULL || len<=0){
		cerr<<"Invalid Parameters"<<endl;
		return;
	}//end if
	int temp;
	for(int ii=len-1;ii>0;--ii)
		for(int jj=0;jj<ii;++jj){
			if(arr[jj]>arr[jj+1]){
				temp=arr[jj+1];
				arr[jj+1]=arr[jj];
				arr[jj]=temp;
			}
		}//end for
}

/* *****************************************
    改进的冒泡算法  排序思想和Buble_Sort2一样，
     但相比较而言，该算法比Buble_Sort2的性能好
 PS:为什么该算法优于Buble_Sort1，因为在每次比较的时候，相邻点之间
  的大小有了先验信息。可以通过设置标志flag进行改进。
********************************************/
void Buble_Sort3(int arr[],int len)
{// 修改的冒泡算法  
	if(arr==NULL || len<=0){
		cerr<<"Invalid Parameters"<<endl;
		return;
	}//end if
	int temp;
	bool flag=true;
	for(int ii=len-1;ii>0&&flag;--ii){
		flag=false;
		for(int jj=0;jj<ii;++jj){
			if(arr[jj]>arr[jj+1]){
				temp=arr[jj+1];
				arr[jj+1]=arr[jj];
				arr[jj]=temp;
				flag=true;	}
		}//end for
	}
}

/* **********************
         归并排序算法 
************************/
void Merge_Sort(int arr[],int p,int r)
{// 对原序列进行分解，利用递归法
	if(p<r){
		int q=(p+r)>>1;//去数组长度的一般[取整]
		Merge_Sort(arr,p,q);
		Merge_Sort(arr,q+1,r);
		Merge(arr,p,q,r);
	}//end if
}
void Merge(int arr[],int p,int q,int r)
{// 合并子序列
	int n1=q-p+1;
	int n2=r-q;
	int *arrL=new int[n1];//临时申请空间用来存储待排序数据
	int *arrR=new int[n2];
	int ii=0;
	int jj=0;
	for(ii=0;ii<n1;++ii)
		arrL[ii]=arr[p+ii];
	for(jj=0;jj<n2;++jj)
		arrR[jj]=arr[q+jj+1];
	//合并开始
	ii=0;jj=0;
	int kk=p;
	while(ii<n1 && jj<n2){
		if(arrL[ii]>=arrR[jj])
			arr[kk++]=arrR[jj++];
		else
			arr[kk++]=arrL[ii++];
	}//end while
	int flag;
	if(ii>q){
		for(flag=jj;flag<n2;++flag)
			arr[kk++]=arrR[flag];}//end if
	else{
		for(flag=ii;flag<n1;++flag)
			arr[kk++]=arrL[flag];}//end else
}