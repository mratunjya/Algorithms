#include<bits/stdc++.h>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    vector<int> nums={1,2,2,3};
        set<int> num;
        int a=nums.size();
        for(int i=0;i<nums.size();i++){
                num.insert(nums[i]);
        }
        if(a==num.size()){
            cout<<"False";
        }
        else{
            cout<<"True";
        }
    
    return 0;
}   
