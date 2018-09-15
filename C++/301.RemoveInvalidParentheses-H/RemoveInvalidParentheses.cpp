//1. First, calculate the number of open/close parentheses that need to be removed.
//2. Use dfs, recursively remove the open/close parentheses, and record the valid results
//2.1 We have to maintain a field "pair", pair>0 when currently the open parentheses are more than close parentheses. And note that if pair<0, then the current state will not lead to a valid solution.
//2.2 If there are several continuous repeated parentheses, then we just remove one of them.

class Solution {
public:
    void remove(string s, int index, int left, int right, int pair, vector<string>& valid){      
        for(int i=index; i<s.size() && pair>=0; ++i){
            if(s[i] == '('){
                if(left>0 && (i==0 || s[i-1]!='(')){
                    remove(s.substr(0,i)+s.substr(i+1), i, left-1, right, pair, valid);
                }
                pair++;
            }
            else if(s[i] == ')'){
                if(right>0 && (i==0 || s[i-1]!=')')){
                    remove(s.substr(0,i)+s.substr(i+1), i, left, right-1, pair, valid);
                }
                pair--;
            } 
        }
        
        if(left==0 && right==0 && pair==0){
            valid.push_back(s);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> valid;
        int left = 0, right = 0, pair = 0;
        for(char ch: s){
            if(ch=='(') left++;
            else if(ch==')' && left>0) left--;
            else if(ch==')')right++;
        }
        remove(s, 0, left, right, 0, valid);
        return valid;
    }
};
