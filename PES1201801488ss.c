int isSorted(int *a, int n)
{
        for(int i=0;i<n-1;i++)
        {
                if(a[i]>a[i+1])
                        return 0;
       }
       return 1;
}

void bubblePass(int *a, int n)
{
       for(int i=0;i<n-1;i++)
       {
        if(a[i]>a[i+1])
        {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
       }
       }
     
       
}

void bubbleSort(int *a, int n)
{
        if(isSorted(a,n))
                return;
        else
        {
                for(int i=0;i<n-1;i++)
                        bubblePass(a,n-i);
        }
}


int numBubblePasses(int *a, int n)
{
     int c=0;
     for(int i=0;i<n-1;i++)
        {
                   if(isSorted(a,n))
                        break;
                else
                {
                  c++;
                   bubblePass(a,n-i);
                   }
        }
        return c;
        
} 

int maxIndex(int *a, int n)
{
        int max=0;
        for(int i=0;i<n;i++)
        {
                if(a[i]>=a[max])
                        max=i;
        }
        return max;
}

void swapWithMax(int *a, int n)
{
        int i=maxIndex(a,n);
        if(i<n-1)
        {
                int temp=a[i];
                a[i]=a[n-1];
                a[n-1]=temp;
               
       }
}


void selectionSort(int *a, int n)
{
        for(int i=n;i>0;i--)
        {
                swapWithMax(a,i);
        }
}


int numSwaps(int *a, int n)
{
    
        int count=0;
        while(!isSorted(a,n))
        {
               
                if(maxIndex(a,n)<n-1)
                {
                        count++;
                        swapWithMax(a,n);
                }
                n--;
                
        }
   
        return count;
}

