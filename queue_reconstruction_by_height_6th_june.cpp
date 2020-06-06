
class Solution {
public:
   
    void update(int idx,int val,vector<int>& bit){
            while(idx<=bit.size()){
                bit[idx]+=val;
                idx+=(idx & -idx);
            }
        }
        
        int sum(int idx,vector<int>& bit){
            int sm=0;
            
            while(idx>0){
                sm+=bit[idx];
                idx-=(idx & -idx);
            }
            
            return sm;
        }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end());
        vector<vector<int> > res(n);
        map<int,int> freq;
        vector<int> bit(n+5,0);
        for(int i=0;i<n;i++){
            update(i+1,1,bit);
        } 
        
        for(int i=0;i<n;i++){
            int l=1,r=n;
            
            while(l<r){
                int m=l+(r-l)/2;
                
                if(sum(m,bit)<people[i][1]+1-freq[people[i][0]]) l=m+1;
                else r=m;
            }
            
            res[l-1]=people[i];
            update(l,-1,bit);
            freq[people[i][0]]++;
        }
        
        return res;
        
        
    }
};
