/*	file:		SelectionSort.cpp
	brief:		Select sort methods implement
	author:		zhonglin
	date:		2018.3.11
	version:	v1.0.0
 */
#include "SortMethods.h"


void SelectionSort(int *pArr)
{
	if(NULL == pArr)
	{
		printf("param is null.\n");
		return;
	}

	/* the min index in every loop*/
	int nMinIndex = 0;
	for(int ii = 0; ii < N; ++ii)
	{
		nMinIndex = ii;
		for(int jj = ii + 1; jj < N; ++jj)
		{
			if(pArr[jj] < pArr[nMinIndex])
			{
				nMinIndex = jj;
			}			
		}
		
		if(nMinIndex != ii)
		{
			Swap(pArr[nMinIndex], pArr[ii]);
		}
	}
}