class Solution {
public:
    vector<int> pre;
    Solution(vector<int>& w) {
        pre.assign(w.size(),0);
        pre[0]=w[0];
        for(int i=1;i<w.size();i++) pre[i]=pre[i-1]+w[i];
    }
    
    int pickIndex() {
        int n=pre.size();
        int l=0,r=n-1;
        int random=rand()%(pre[n-1]);
        
        while(l<r){
            int m=l+(r-l)/2;
            
            if(pre[m]<=random) l=m+1;
            else r=m;
        }
        
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */