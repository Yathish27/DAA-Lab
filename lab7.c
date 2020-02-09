#include"mergeSort.h"
#include<stdlib.h>
void mergeSortedHalfs(int *a, int start, int mid, int end)
{
    int i, j, k; 
    int n1 = mid - start + 1; 
    int n2 = end - mid; 
  
    int L[n1];
    int R[n2];
 
    for (i = 0; i < n1; i++) 
        L[i] = a[start + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[mid + 1+ j]; 
  
    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k++] = L[i++]; 
        } 
        else
        { 
            a[k++] = R[j++]; 
        } 
    } 
    while (i < n1) 
    { 
        a[k++] = L[i++]; 
    } 
    while (j < n2) 
    { 
        a[k++] = R[j++]; 
    } 
} 
void mergeSort(int *a, int start, int end)
{
    if (start < end) 
    {        
        int mid = start+(end-start)/2; 
        mergeSort(a, start, mid); 
        mergeSort(a, mid+1, start); 
        mergeSortedHalfs(a, start, mid,end); 
    } 
}
void insertionSort(int *a, int start, int end)
{
    int i, key, j; 
    for (i = start; i < end; i++) { 
        key = a[i]; 
        j = i - 1; 
 
        while (j >= 0 && a[j] > key) { 
            a[j + 1] = a[j]; 
            j = j - 1; 
        } 
        a[j + 1] = key; 
    } 
} 

void selectiveMergeSort(int *a, int start, int end, int parameter)
{
	if(parameter<end)
	{
		if(start < end)
		{
		int mid = start+(end-start)/2;
		mergeSort(a, start, mid); 
        	mergeSort(a, mid+1, start); 
		mergeSortedHalfs(a,start,mid,end);
		}

	}
	else
	{
		insertionSort(a,start,end);
	}
}
		

