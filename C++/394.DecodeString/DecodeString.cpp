//Every time we meet a '[', we can treat it as a subproblem, so we store the previous result and repeated times in stack, and start a new subproblem. 
//And every time we meet a ']', this means a subproblem is done, we can just repeate the current result, and attach it to the end of the previous result. 

//1. Scan the string
//1.1 If we meet a number, we save it as the repeated times.
//1.2 If we meet a '[', which means a new subproblem is coming, then we store the previous result in stack of string, and store the repeated times in stack of int. And treat the rest of string as a new subproblem.
//1.3 When we meet a ']', which means the subproblem is done, then we pop out the repeated times and previous result from the stack, repeate the current result, and finally attach it to the end of the previous result.

class Solution {
public:
    string decodeString(string s) {
        stack<string> sStr;
        stack<int> sInt;
        string pre = "";
        string cur;
        int cnt = 0;
        int start;
        for(int i=0; i<s.size(); ++i){
            if(s[i]>='0'&&s[i]<='9'){
                start = i;
                while(i<s.size()-1 && s[i+1]>='0' && s[i+1]<='9') i++;
                cnt = stoi(s.substr(start, i-start+1));
            }
            else if(s[i]=='['){
                sInt.push(cnt);
                sStr.push(pre);
                pre = "";
                cnt = 0;
            }
            else if(s[i]==']'){
                cur = pre;
                pre = sStr.top();
                cnt = sInt.top();
                sStr.pop();
                sInt.pop();
                while(cnt--){
                    pre += cur;
                }
            }
            else{
                pre.push_back(s[i]);
            }
        }
        return pre;
    }
};
