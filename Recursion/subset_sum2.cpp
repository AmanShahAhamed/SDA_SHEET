class Solution {
public:
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
    
    void fun(vector<int>nums,int start,int end,unordered_set<vector<int>,hashFunction> &s,vector<int>ans){
        if(start>=end){
            if(ans.size()!=0)
                sort(ans.begin(),ans.end());
            s.insert(ans);
            return;
        }
        vector<int> temp=ans;
        fun(nums,start+1,end,s,temp);
        vector<int> ntemp=ans;
        ntemp.push_back(nums[start]);
        fun(nums,start+1,end,s,ntemp);      
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_set<vector<int>,hashFunction> s;
        fun(nums,0,nums.size(),s,{});
        vector<vector<int>> ans;
        for(auto it : s)
            ans.push_back(it);
        return ans;
    }
};
