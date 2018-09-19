class Solution {
public:
    bool isNumber(string s) {
        //remove leading and ending space
        s = removeSpace(s);
        if(s=="") return false;
        
        //find e
        int eIndex = containE(s);
        if(eIndex){
            //if contains e, then we split the string to two parts
            //part1 can be a integer or decimals
            //part2 must be a integer
            //cout<<s<<endl;
            string s1 = s.substr(0,eIndex);
            string s2 = s.substr(eIndex+1);
            //cout<<s1<<endl;
            //cout<<s2<<endl;
            if(validSign(s1) && validSign(s2)){
                if(s1[0]=='-'||s1[0]=='+') s1 = s1.substr(1);
                if(s2[0]=='-'||s2[0]=='+') s2 = s2.substr(1);
                return isDecimal(s1)&&isInteger(s2);
            }
            else return false;
        }
        else{
            //if no e, then it should be a decimal
            //cout<<s<<endl;
            if(validSign(s)){
                if(s[0]=='-'||s[0]=='+') s = s.substr(1);
                return isDecimal(s);
            }
            else return false;
        }
        
    }
    
    string removeSpace(string s){
        int start = 0, end = s.size()-1;
        while(start<s.size() && s[start]==' ') start++;
        while(end>=start && s[end]==' ') end--;
        if(end<start) return "";
        else return s.substr(start, end-start+1);
    }
    
    int containE(string s){
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='e') return i;
        }
        return 0;
    }
    
    bool validSign(string s){
        int signNum = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='+' || s[i]=='-') signNum++;
            else break;
        }
        return (signNum<=1)?true:false;
    }
    
    bool isDecimal(string s){
        if(s=="") return false;
        int dotNum = 0;
        int nums = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i]>='0' &&s[i]<='9') nums++;
            else if(s[i]=='.'){
                dotNum++;
                if(dotNum>1) return false;
            }
            else return false;
        }
        return (nums>0)?true:false;
    }
    
    bool isInteger(string s){
        if(s=="") return false;
        for(int i=0; i<s.size(); ++i){
            if(s[i]>='0' &&s[i]<='9') continue;
            else return false;
        }
        return true;
    }
};
