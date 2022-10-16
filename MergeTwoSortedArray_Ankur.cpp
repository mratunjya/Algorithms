#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

vector<int> merge(vector<int> v1,vector<int> v2,int n1,int n2){
    int i=0,j=0,k=0;
    vector<int>v;
    v1.emplace_back(INF);
    v2.emplace_back(INF);
    while(k<(n1+n2)){
        if(v1[i]<v2[j])
            v.emplace_back(v1[i++]);
        else
            v.emplace_back(v2[j++]);
        k++;
    }
    return v;
}

int main()
{
    int n1,n2,i,x;
    vector<int> v1,v2,v;
    cout<<"Enter size of Array1 : ";
    cin>>n1;
    cout<<"Enter Elements of Array1 :-\n";
    for(i=0;i<n1;i++){
        cin>>x;
        v1.emplace_back(x);
    }
    
    cout<<"Enter size of Array2 : ";
    cin>>n2;
    cout<<"Enter Elements of Array2 :-\n";
    for(i=0;i<n2;i++){
        cin>>x;
        v2.emplace_back(x);
    }
    
    v=merge(v1,v2,n1,n2);
    cout<<"\nMerged Sorted Array :-";
    for(i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}
