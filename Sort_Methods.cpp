// Sort_Test.cpp : ���������㷨
//	1.��������
//	2.ð������
//  3.�Ľ���ð�ݷ�
//	4.�鲢����

#include "stdafx.h"
#include <iostream>
#include <exception>

using namespace std;

void Insertion_Sort(int arr[],int len);//���������㷨��������

void Buble_Sort1(int arr[],int len);//��ªð�������㷨��������

void Buble_Sort2(int arr[],int len);//ð�������㷨��������

void Buble_Sort3(int arr[],int len);//�Ľ�ð�������㷨��������

void Merge_Sort(int arr[],int p,int r);//�鲢������������
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
      ���������㷨 
����˼�룺��һ����¼���뵽�Ѿ��ź����������У��Ӷ��õ�
һ���µġ���¼��1�������  PS:ʱ�临�Ӷ�Ҳ��O(n^2) 
************************/
void Insertion_Sort(int arr[],int len)
{// ��������
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
        ��ªð�������㷨 
��С�������� ���õ�����ii��Ϊ�ڱ������ó��׷�������˼���ǣ�
(1)���һ�����һ���Ƚϣ����С���򻥻������򣬲�����
(2)���һ������ڶ����Ƚϣ����С���򻥻������򣬲�����
...����һֱ��ȥ��һ��ѭ�������������ֵ�ĵ�϶������
*******************************************/
void Buble_Sort1(int arr[],int len)
{// ��ª��ð�ݷ� 
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
              ð���㷨 
��С�������� ���õ�����ii��Ϊ�ڱ������ó��׷�������˼���ǣ�
(1)��һ����ڶ����Ƚϣ���������򻥻������򣬲�����
(2)�ڶ�������������Ƚϣ����С���򻥻������򣬲�����
...����һֱ��ȥ��һ��ѭ�������������ֵ�ĵ�϶������
********************************************/
void Buble_Sort2(int arr[],int len)
{// ð���㷨  
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
    �Ľ���ð���㷨  ����˼���Buble_Sort2һ����
     ����Ƚ϶��ԣ����㷨��Buble_Sort2�����ܺ�
 PS:Ϊʲô���㷨����Buble_Sort1����Ϊ��ÿ�αȽϵ�ʱ�����ڵ�֮��
  �Ĵ�С����������Ϣ������ͨ�����ñ�־flag���иĽ���
********************************************/
void Buble_Sort3(int arr[],int len)
{// �޸ĵ�ð���㷨  
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
         �鲢�����㷨 
************************/
void Merge_Sort(int arr[],int p,int r)
{// ��ԭ���н��зֽ⣬���õݹ鷨
	if(p<r){
		int q=(p+r)>>1;//ȥ���鳤�ȵ�һ��[ȡ��]
		Merge_Sort(arr,p,q);
		Merge_Sort(arr,q+1,r);
		Merge(arr,p,q,r);
	}//end if
}
void Merge(int arr[],int p,int q,int r)
{// �ϲ�������
	int n1=q-p+1;
	int n2=r-q;
	int *arrL=new int[n1];//��ʱ����ռ������洢����������
	int *arrR=new int[n2];
	int ii=0;
	int jj=0;
	for(ii=0;ii<n1;++ii)
		arrL[ii]=arr[p+ii];
	for(jj=0;jj<n2;++jj)
		arrR[jj]=arr[q+jj+1];
	//�ϲ���ʼ
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