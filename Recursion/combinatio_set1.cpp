    struct hashFunction 
{
  size_t operator()(const vector<int> 
                    &myVector) const 
  {
    std::hash<int> hasher;
    size_t answer = 0;
      
    for (int i : myVector) 
    {
      answer ^= hasher(i) + 0x9e3779b9 + 
                (answer << 6) + (answer >> 2);
    }
    return answer;
  }
};
    
    void fun(vector<int> num,int sum,int start,int end,vector<int> v,unordered_set<vector<int>,hashFunction> &ans){
        
        if(sum==0){
            if(v.size()!=0)
                sort(v.begin(),v.end());
            ans.insert(v);
            return;
        }
        
        for(int i=start;i<end;i++){
            if(sum-num[i]>=0){
                vector<int> temp=v;
                temp.push_back(num[i]);
                fun(num,sum-num[i],start,end,temp,ans);
            }
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_set<vector<int>,hashFunction> ans;
        fun(candidates,target,0,candidates.size(),{},ans);
        vector<vector<int>> v;
        for(auto it :ans ){
            v.push_back(it);
        }
        return v;
    }
