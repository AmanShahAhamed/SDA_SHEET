 int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=1,j=0,res=1,plat=1;
    	while(i<n & j<n){
    	     if(arr[i]>dep[j]){
    	         plat--;
    	         j++;
    	     }
    	     else
    	       {
    	           i++;
    	           plat++;
    	       }
    	   res=max(res,plat);
    	}
    	return res;
    }
