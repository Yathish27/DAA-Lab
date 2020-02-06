#include "session5_sort.h"
#include <time.h>
#include <stdio.h>

double time_elapsed(struct timespec start, struct timespec end) {
double t;
t = (end.tv_sec - start.tv_sec); //diff of tv_sec
t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
return t;
}

long int InsertionSort(Record* A, int n)
{
    long int count=0;
    int i,j,k;
    for(i=1;i<n;i++)
    {
        Record temp=A[i];
        for(j=i-1;j>=0;j--)
        {
            count++;
            if(temp.serialnumber>A[j].serialnumber)
                break;
        }
        for(k=i;k>j;k--)
        {
            A[k]=A[k-1];
        }
        A[j+1]=temp;
    }
    return count;
}

long int BubbleSort(Record* A, int n)
{
   int i,j;long int count=0;int swaps;
   for(i=0;i<n-1;i++)
   {
        swaps=0;
        for(j=0;j<n-i-1;j++)
        {
            count++;
            if(A[j].serialnumber > A[j+1].serialnumber)
            {
                Record temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                swaps=1;
            }
        }
        if(swaps==0)
            break;
   }
   return count;
}

long int SelectionSort(Record* A, int n)
{
    int i,j;long int count=0;int min=0;
    for(i=0;i<n-1;i++)
    {
        Record temp=A[i];min=i;
        for(j=i+1;j<n;j++)
        {
            count++;
            if(A[j].serialnumber < A[i].serialnumber)
            {
                temp=A[j];min=j;
            }
        }
        if(min!=i)
        {
            Record t=A[min];
            A[min]=A[i];
            A[i]=t;
        }
    }
    return count;

}

int main()
{
        char line[50];
        long int count;
        int size;
        struct timespec start, end; //timestamps
       
        FILE *fp = fopen("session5_sort_ip_rand096k.txt","r+");
        fscanf(fp,"%d",&size);
        Record B[size];
        Record C[size];
        printf("%d\n",size);
       
        for(int i=0;i<size;i++)
        {
               
                fscanf(fp,"%li",&B[i].serialnumber);
                fscanf(fp,"%d",&B[i].score);
        }
       
        //Insertion Sort
        for(int i=0;i<size;i++)
        {
                C[i].serialnumber = B[i].serialnumber;
                C[i].score = B[i].score;
        }
        clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
        count = InsertionSort(B,size);
        clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
        printf(time_elapsed(start, end));
        printf(" %li\n",count);


        for(int i=0;i<size;i++)
        {
                B[i].serialnumber = C[i].serialnumber;
                B[i].score = C[i].score;
        }
       
       
       
        //Bubble Sort
        for(int i=0;i<size;i++)
        {
                C[i].serialnumber = B[i].serialnumber;
                C[i].score = B[i].score;
        }
        clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
        count = BubbleSort(B,size);
        clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
        printf(time_elapsed(start, end));
        printf(" %li\n",count);
        for(int i=0;i<size;i++)
        {
                B[i].serialnumber = C[i].serialnumber;
                B[i].score = C[i].score;
        }
       
        //Selection Sort
        for(int i=0;i<size;i++)
        {
                C[i].serialnumber = B[i].serialnumber;
                C[i].score = B[i].score;
        }
        clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
        count = SelectionSort(B,size);
        clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
        printf(time_elapsed(start, end));
        printf(" %li\n,count);
        for(int i=0;i<size;i++)
        {
                B[i].serialnumber = C[i].serialnumber;
                B[i].score = C[i].score;
        }
}
