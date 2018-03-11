#include "SortMethods.h"
#include "InOutPut.h"
#include <ctime>
#include <exception>

struct BNode{
	int num;
	struct BNode *next;
};
typedef struct BNode Node;
Node **arrB=(Node**)malloc(NBucket*sizeof(Node*));

void BucketSort_Test(int *arr,double &ltime)
{
	SetBuckets(arrB);
	double tstart=clock();
	Bucket_Sort(arr);
	double tend=clock();
	ltime=tend-tstart;
	//Print_Buckets(arrB);
}

void SetBuckets(Node **arrB)
{
	for(int ii=0;ii<NBucket;++ii){
		arrB[ii]=(Node *)malloc(sizeof(Node));
		arrB[ii]->next=NULL;
		arrB[ii]->num=0;
	}
}
void Bucket_Sort(int *arr)
{
	if(arr==NULL)
		throw exception("Invalid Parameters.");
	for(int ii=0;ii<N;++ii)
		Insert_Buckets(arr[ii]);
}

void Insert_Buckets(int temp)
{
	Node *pNode=(Node *)malloc(sizeof(Node));
	pNode->next=NULL;
	pNode->num=temp;

	int flag=temp/(NBucket-1);
	Node *ptr=arrB[flag];
	if(ptr->next==NULL)
		ptr->next=pNode;
	else
		arrB[flag]=InsertSort(pNode,flag);
}

Node *InsertSort(Node *pNode,int flag)
{
	Node *phead=arrB[flag];
	Node *ptr=phead;
	while(ptr->next!=NULL && ptr->next->num <=pNode->num)
		ptr=ptr->next;
	pNode->next=ptr->next;
	ptr->next=pNode;
	return phead;
}

void Print_Buckets(Node **arrB)
{
	Node *ptr=NULL;
	for(int jj=0;jj<NBucket ;++jj){
		ptr=arrB[jj];
		while(ptr->next!=NULL){
			ptr=ptr->next;
			cout<<ptr->num<<'\t';
		}
	}
	cout<<endl;
}