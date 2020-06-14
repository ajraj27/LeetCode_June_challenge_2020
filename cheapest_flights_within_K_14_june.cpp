
vector<pair<int,int> > g[105];
vector<int> vis(105);

class Solution {
public:
    int djisktra(int src,int dst,int K){
        priority_queue<vector<int>,vector<vector<int> >,greater<vector<int> > > pq;
        pq.push({0,src,K+1});
        
        while(!pq.empty()){
            auto z=pq.top();
            pq.pop();
            
            int u=z[1];
            int cost=z[0];
            int p=z[2];
            
            if(u==dst) return cost;
            
            if(p>0)
                for(auto v:g[u])
                    pq.push({cost+v.second,v.first,p-1});
            
        }
        
        return -1;
        
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        for(int i=0;i<flights.size();i++){
            g[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        int ans=djisktra(src,dst,K);
        for(int i=0;i<n;i++) g[i].clear();
        return ans;
        
        
    }
    
   
};