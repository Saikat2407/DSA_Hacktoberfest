#include<bits/stdc++.h>
using namespace std;

vector<int> duplicatesInArray(int arr[], int n){
    vector<int>ans;
    for(int i=0;i<n;i++){
        int key=arr[i]%n;
        arr[key]+=n;
    }
    for(int i=0;i<n;i++){
        if((arr[i]/n)>=2){
            ans.push_back(i);
        }
    }
    if(ans.size()==0){
        return {-1};
    }
    else return ans;
}


int main(){
    int arr[]={4,2,1,0,1,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>res=duplicatesInArray(arr,n);
    cout<<"The repeating elements are: "<<endl;
    for(int i:res){
        cout<< i <<" "<<endl;
    } 
    return 0;
    }
