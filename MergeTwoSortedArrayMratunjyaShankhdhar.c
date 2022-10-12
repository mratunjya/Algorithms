// Merge two Sorted Arrays

#include <stdio.h>

int main()
{
    int a[100],b[100],c[200],i,j,k,n,m;
    printf("Enter the size of first array: ");
    scanf("%d",&n);
    printf("Enter the size of second array: ");
    scanf("%d",&m);
    printf("Enter the elements of first array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the elements of second array: ");
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    i=0;
    j=0;
    k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n)
    {
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m)
    {
        c[k]=b[j];
        j++;
        k++;
    }
    printf("The merged array is: ");
    for(i=0;i<n+m;i++)
    {
        printf("%d ",c[i]);
    }
    return 0;
}