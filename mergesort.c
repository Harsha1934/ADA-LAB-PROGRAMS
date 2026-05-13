#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int a[],int l,int m,int h)
{
    int i=l;
    int j=m+1;
    int k=l;
    int b[h+1];
    while(i<=m && j<=h)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++,k++;
        }
        else
        {
            b[k]=a[j];
            j++,k++;
        }
    }
    while(i<=m)
    {
        b[k]=a[i];
        i++,k++;
    }
     while(j<=h)
    {
        b[k]=a[j];
        j++,k++;
    }
     for (int p = l; p <= h; p++)
    {
        a[p] = b[p];
    }

}
void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
    float st=clock();
    mergesort(arr,0,n-1);
    float end=clock();
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("%f ",end-st);
    return 0;
}

