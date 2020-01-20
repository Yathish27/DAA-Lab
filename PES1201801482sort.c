int isSorted(int *a, int n)
{
        for(int i=0;i<n-1;i++)
                if(a[i]>a[i+1])
                        return 0;
        return 1;
}

void bubblePass(int *a, int n)
{
        int temp;
        for(int j=0;j<n-1;j++)
                if(a[j]>=a[j+1])
                {
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                }
}


void bubbleSort(int *a, int n)
{
        int i=0;
        while(!isSorted(a,n))
        {
                bubblePass(a,n-i);
                i++;
        }
}

/*int numBubblePasses(int *a, int n)
{
        if(isSorted(a,n))
                return 0;
        for(int i=0;i<n-1;i++)
        {
                bubblePass(a,n-i);
                if(isSorted(a,n))
                        return i+1;
        }
}*/

int numBubblePasses(int *a, int n)
{
        int count=0;
        int i=0;
        while(!isSorted(a,n))
        {
                count++;
                bubblePass(a,n-i);
                i++;
        }
        return count;
}

int maxIndex(int *a, int n)
{
        int pos = 0;
        for(int i=0;i<n-1;i++)
                if(a[i+1]>=a[pos])
                        pos = i+1;
        return pos;
}

void swapWithMax(int *a, int n)
{
        int i = maxIndex(a,n);
        if(i<n-1)
        {
                int temp = a[i];
                a[i] = a[n-1];
                a[n-1] = temp;
        }
}

void selectionSort(int *a, int n)
{
        for(int i=n-1; i>=1; i--)
                swapWithMax(a,i+1);
}

int numSwaps(int *a, int n)
{
        int count = 0;
        
        while(!isSorted(a,n))
        {
                 int i = maxIndex(a,n);
                 if(i<n-1)
                 {
                        count++;
                        swapWithMax(a,n);
                 }
                 n--;
        }
        
        return count;
}

/*gcc -Wall PES1201801482sort.c sort_sampletest.c -o sort_sampletests.out
./sort_sampletests.out
 gcc -Wall PES1201801482sort.c sort_tests.o -o sort_tests.out

*/


