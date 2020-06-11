class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        int idx=0;
        
        while(idx<=end){
            if(nums[idx]==0){
                swap(nums[idx],nums[start]);
                start++;
                idx++;
            } else if(nums[idx]==2){
                swap(nums[idx],nums[end]);
                end--;
            } else idx++;
        }
        
    }
};