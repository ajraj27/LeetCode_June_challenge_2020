class Solution {
public:
    int fact[10];
    vector<string> nums;
    
    string kth(int k){
        int n=nums.size();
        if(n==0) return "";
        
        int first_idx=k/fact[n-1];
        string first_digit=nums[first_idx];
        k%=fact[n-1];
        nums.erase(nums.begin()+first_idx);
       return first_digit.append(kth(k));
        
    }
    string getPermutation(int n, int k) {
        fact[0]=1;
        nums.resize(n);
        for(int i=1;i<10;i++) fact[i]=i*fact[i-1];
        for(int i=0;i<n;i++) nums[i]=to_string(i+1);
        
        return kth(k-1);
        
        
        
    }
};