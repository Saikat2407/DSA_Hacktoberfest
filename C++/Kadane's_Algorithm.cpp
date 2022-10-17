    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        int res = INT_MIN , sum=0;
        for(int i=0;i<n;i++)
        {
            sum = arr[i]+sum;
            res=max(res,sum);
            if(sum<0)
            sum=0;
        }
        return res;
        
    }
};
