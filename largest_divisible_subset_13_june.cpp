class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n,1);
        int mx=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0) dp[i]=max(dp[i],1+dp[j]);
            }
            
            mx=max(mx,dp[i]);
        }
        
        vector<int> res;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==mx){
                res.push_back(nums[i]);
                mx--;
            }
        }
        
        return res;
        
        
    }
};