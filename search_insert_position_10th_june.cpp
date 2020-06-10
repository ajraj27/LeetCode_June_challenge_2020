class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        if(target<=nums[0]) return 0;
        else if(target>nums[n-1]) return n;
        
        while(l<r){
            int m=l+(r-l)/2;
            
            if(nums[m]>=target) r=m;
            else l=m+1;
        }
        
        return l;
        
    }
};