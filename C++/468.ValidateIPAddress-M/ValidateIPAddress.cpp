//1.I want to define two helper function: isIPv4 and isIPv6
//1.1 if the input contains a dot, then it can be IPv4
//1.2 if the input contains a colon, then it can be IPv6

//2.For the input that can be ipv4
//2.1 Split the input by dot, and we get a vector of string.
//2.2 If the number of string is not 4, then it is not ipv4
//2.3 If the length of each string is 0 or greater then 3, then it is not ipv4
//2.4 If each number does not in the range from 0-255, then it is not ipv4
//2.5 If leading zeros, then it is not ipv4

//2.For the input that can be ipv6
//2.1 Split the input by colon, and we get a vector of string.
//2.2 If the number of string is not 8, then it is not ipv6
//2.3 If the length of each string is 0 or greater then 4, then it is not ipv6
//2.4 If not 0-9 a-f A-F, then it is not ipv6

class Solution {
public:
    vector<string> split(string IP, char ch){
        vector<string> res;
        int index = 0;
        res.push_back("");
        for(char item: IP){
            if(item==ch){
                res.push_back("");
                index++;
            }
            else res[index].push_back(item);
        }
        return res;
    }
    bool isIPv4(string IP){
        vector<string> nums = split(IP, '.');
        if(nums.size()!=4) return false;
        for(int i=0; i<4; ++i){
            if(nums[i].size()==0) return false;
            if(nums[i].size()>3) return false;
            if(nums[i]>="0" && nums[i]<="255"){
                if(nums[i].size()>1 && nums[i][0]=='0') return false;
            }
            else return false;
        }
        return true;
    }
    
    bool isIPv6(string IP){
        vector<string> nums = split(IP, ':');
        if(nums.size()!=8) return false;
        for(int i=0; i<8; ++i){
            if(nums[i].size()==0) return false;
            if(nums[i].size()>4) return false;
            for(int j=0; j<nums[i].size(); ++j){
                if((nums[i][j]>='0' && nums[i][j]<='9') ||
                    (nums[i][j]>='a' && nums[i][j]<='f') ||
                    (nums[i][j]>='A' && nums[i][j]<='F'))
                    continue;
                else return false;
            }
        }
        return true;
    }
    
    string validIPAddress(string IP) {
        if(IP.size()>40) return "Neither";
        int canbe = 0;
        for(char ch: IP){
            if(ch=='.'){
                canbe = 4;
                break;
            }
            else if(ch==':'){
                canbe = 6;
                break;
            }
            else continue;
        }
        if(canbe==4 && isIPv4(IP)) return "IPv4";
        else if(canbe==6 && isIPv6(IP)) return "IPv6";
        else return "Neither";
    }
};

