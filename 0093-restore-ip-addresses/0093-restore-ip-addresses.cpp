class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> IPs;
        vector<string> temp;
        ok(temp,IPs,s,0);
        return IPs;
    }
    
    void ok(vector<string>& temp,vector<string>& IPs,string s,int index){
        if(index == s.length() && temp.size() == 4){
            string validIP = temp[0] + '.' + temp[1] + '.' + temp[2] + '.' + temp[3];
            IPs.push_back(validIP);
            return;
        }
        
        string tempStr = "";
        for(int i=index ; i < s.size() && temp.size()<4;i++){
            // if(s[i]-'0' > 9) continue;
            tempStr += s[i];
            int tempInt = stoi(tempStr);
            if(0<=tempInt && tempInt<=255){
                temp.push_back(tempStr);
                ok(temp,IPs,s,i+1);
                temp.pop_back();
            }
            
            if(tempInt<=0 || tempInt>255)
                break;
        }
        
    }
};