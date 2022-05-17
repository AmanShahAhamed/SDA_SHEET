void fun(vector<int> arr,int start,int end,vector<int> &ans,int sum){
    if(start>=end){
        ans.push_back(sum);
        return;
    }
    fun(arr,start+1,end,ans,sum);
    fun(arr,start+1,end,ans,sum+arr[start]);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        fun(arr,0,N,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
