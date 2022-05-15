struct Item;
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp( struct Item a, struct Item b) {
       double r1=double(a.value*1.0)/double(a.weight*1.0);
       double r2=double(b.value*1.0)/double(b.weight*1.0);
       return r1>r2;
       
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        double val=0.0;
        for(int i=0;i<n;i++){
            if(W-arr[i].weight>=0){
                val+=arr[i].value;
                W-=arr[i].weight;
            }else{
                 val+=(double(arr[i].value*1.0)/double(arr[i].weight*1.0))*W;
                 break;
            }
            if(W==0) break;
           
        }
        return val;
        
    }
