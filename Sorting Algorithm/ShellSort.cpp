#include "SortMethods.h"

void ShellSort(int *pArr)
{
	if(NULL == pArr)
	{
		printf("param is null.\n");
		return;
	}

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