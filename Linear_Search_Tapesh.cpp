#include<iostream>
using namespace std;
int match(int arr[],int n,int k){
  for(int i=0;i<n;i++){
    if(arr[i]==k){
      return i;
    }
    }
    return 0;
  }
int main()
{
  cout<<"enter n:"<<endl;
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"enter key to find:"<<endl;
  int k;
  cin>>k;
  int b=match(arr,n,k);
  if(b==0){
    cout<<"No matched key array";
  }
  else{
    cout<<"matched index:"<<b;
  }
  return 0;
}
