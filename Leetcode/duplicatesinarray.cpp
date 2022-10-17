https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int n:nums){
            n=abs(n);
            if(nums[n-1]>0){
                nums[n-1] *=-1;
            }
            else{
                ans.push_back(n);
            }
        }
        return ans;
    }
}

int main(){
    int arr[]={4,2,1,0,1,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>res=findDupliactes(arr,n);
    cout<<"The repeating elements are: "<<endl;
    for(int i:res){
        cout<< i <<" "<<endl;
    } 
    return 0;
    }