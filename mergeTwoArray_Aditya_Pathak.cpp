#include <iostream>
using namespace std;

void merge(int arr1[],int arr2[],int n1,int n2){
    int i=0,j=0,k=0;
    int merged[n1+n2];
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            merged[k]=arr1[i];
            k++;
            i++;
        }
        else{
            merged[k]=arr2[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        merged[k]=arr1[i];
        k++;
        i++;
    }
     while(j<n2){
        merged[k]=arr2[j];
        k++;
        j++;
    }
    cout<<"Sorted array is: ";
    for(i=0;i<(n1+n2);i++){
        cout<<merged[i]<<" ";
    }
}

int main()
{
    int arr1[]={2,4,7,9,12,15,18};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[]={1,3,6,10,14};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    merge(arr1,arr2,n1,n2);
    
}
