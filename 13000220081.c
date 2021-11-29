/*a)Write a program to sort an array using Insertion sort in C.
  b)Write a program to sort an array using Merge sort in C.*/

#include <stdio.h>
#include<stdlib.h>
#define MAX 10

int merge();
void merge_sort (int *, int , int );
void merging (int *, int, int, int );
int insertion();
void BinaryInsertionSort(int*,int);
int binarySearch(int*,int,int,int);

int main()
{
    int n;
    char ch;
    do
    {
        printf("\nMain Menu : ");
        printf("\n1.Merge Sort.");
        printf("\n2.Insertion Sort.");
        printf("\n3.Exit form the program.");
        printf("\nEnter your choice.");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("\n\nYour choice is Merge sort.");
                   merge();
                   break;
            case 2:printf("\n\nYour choice is Insertion sort.");
                   insertion();
                   break;
            case 3:printf("\nExit from the program.");
                   printf("\nThank You.");
                   exit(0);
                   break;
            default:printf("\nInvalid Input.");
                    break;
        }printf("\nDo you want to continue ? (if yes type Y or y) : ");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y' || ch=='Y');
}

int merge()
{
    int i,a[MAX];
    printf("\nList before sorting. : ");
    for(i=0;i<MAX;i++)
        scanf("%d",&a[i]);
    merge_sort(a,0,MAX-1);
    printf("\nSorted List : ");
    for(i=0;i<MAX;i++)
       printf("%d ",a[i]);
    printf("\n");
    return 0;
}

void merge_sort(int *a,int left,int right)
{
    int mid;
    if (left!=right)
    {
        mid=(left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merging (a,left,mid,right);
    }
}

void merging (int *a, int left, int mid, int right)
{
    int i,j,aux[MAX],k=0;
    for (i= left,j=mid+1;i<=mid && j<=right;k++)
    {
        if(a[i]<a[j])
            aux[k]=a[i++];
        else
            aux[k]=a[j++];
    }
    for(;i<=mid;i++)
        aux[k++]=a[i];
    for(;j<=right;j++)
        aux[k++]=a[j];
    for(i=0;i<k;i++)
        a[left++]=aux[i];
}

int insertion()
{
    int n,i,arr[MAX];
    n=sizeof(arr)/sizeof(arr[0]);
    printf("\nList before sorting. : ");
    for(i=0;i<MAX;i++)
        scanf("%d",&arr[i]);
    BinaryInsertionSort(arr,n);
    printf("\nAfter insertion sort the Sorted array is : ");
    for (i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

void BinaryInsertionSort(int *arr, int n)
{
    int i,loc,j,key;
    for(i=1;i<n;++i)
    {
        j=i-1;
        key=arr[i];
        loc=binarySearch(arr,key,0,j);
        while(j>=loc)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int binarySearch(int *arr, int item, int left, int right)
{
    int mid;
    if(right<=left)
        return(item>arr[left])?(left+1):left;
    mid=(left+right)/2;
    if(item==arr[mid])
        return mid+1;
    if(item>arr[mid])
        return binarySearch(arr,item,mid+1,right);
    else
        return binarySearch(arr,item,left,mid-1);
}
