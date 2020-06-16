class Solution {
public:
    vector<string> ipv4array(string& IP){
        string str="";
        vector<string> res;
        for(int i=0;i<IP.length();i++){
            if(IP[i]=='.'){
                res.push_back(str);
                str="";
            
            } else str.push_back(IP[i]);
        }
        
        res.push_back(str);
        
        return res;
    }
    
    vector<string> ipv6array(string& IP){
        string str="";
        vector<string> res;
        for(int i=0;i<IP.length();i++){
            if(IP[i]==':'){
                res.push_back(str);
                str="";
            } else str.push_back(IP[i]);
        }
        
        res.push_back(str);
        
        return res;
    }
    
    string validIPAddress(string IP) {
        vector<string> a=ipv4array(IP);
        vector<string> b=ipv6array(IP);
        
        if(a.size()==4){
            for(string& x:a){
                if(x.length()==0 || (x.length()>1 && x[0]=='0') || x<"0" || x>"255" || x.length()>3) return "Neither";
            }
            
            return "IPv4";
            
        } else if(b.size()==8){
            for(string& x:b){
                if(x.length()==0 || x.length()>4) return "Neither";
                for(char& c:x) if((c>='0' && c<='9') || (c>='a' && c<='f') || (c>='A' && c<='F') ) continue;
                else return "Neither";
            } 
            return "IPv6";
        } else return "Neither";
    }
};