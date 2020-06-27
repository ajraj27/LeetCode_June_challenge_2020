class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        
        for(int i=1;i<=n;i++){
            int sqr=sqrt(i);
            if(sqr*sqr==i) v.push_back(i);
        }
        
        vector<long long int> dp(n+1,INT_MAX);
        dp[0]=0;
        

        for(int i=1;i<=n;i++){
            for(int j=0;j<v.size();j++)
                if(i>=v[j])
                    dp[i]=min(dp[i],1+dp[i-v[j]]);
        }
        
        return dp[n];
    }
};