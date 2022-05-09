
int fun(vector<int> arr,int n){
	 int ans=arr[0];
      int max_prod=arr[0],min_prod=arr[0];
      for(int i=1;i<=n;i++){
         if(arr[i]<0)
            swap(max_prod,min_prod);
         min_prod=min(arr[i],min_prod*arr[i]);
         max_prod=max(arr[i],max_prod*arr[i]);
         ans=max(ans,max_prod);
      }
      return ans;
}

int maximumProduct(vector<int> &arr, int n)
{  
	return fun(arr,n-1);
}
