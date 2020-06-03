class Solution {
public:
    
   static bool cmp(vector<int>& a,vector<int>& b){
        if(abs(a[0]-a[1])>abs(b[0]-b[1])) return true;
        return false;
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        sort(costs.begin(),costs.end(),cmp);
        
        int ctr1=0,ctr2=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if((costs[i][0]<costs[i][1] && ctr1<n/2) || ctr2==n/2) ctr1++,ans+=costs[i][0];
            else ctr2++,ans+=costs[i][1];
        }
        
        return ans;
    }
};