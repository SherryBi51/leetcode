//If s[i]==p[j], then DP[i+1][j+1]=DP[i][j]
//If p[i]=='.', then DP[i+1][j+1]=DP[i][j]
//If p[i]=='*'
    //If p[i-1]!=s[i] && p[i-1]!='.', then "zero", DP[i+1][j+1] = DP[i+1][j-1]
    //if "zero", DP[i+1][j+1] = DP[i+1][j-1]
    //if "single", DP[i+1][j+1] = DP[i+1][j]
    //if "multiple", DP[i+1][j+1] = DP[i][j+1]


class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> DP(s.size()+1, vector<bool>(p.size()+1, false));
        DP[0][0] = true;
        for(int i=1; i<p.size(); ++i){
            if(p[i]=='*' && DP[0][i-1]) DP[0][i+1] = true;
        }
        for(int i=0; i<s.size(); ++i){
            for(int j=0; j<p.size(); ++j){
                if(s[i]==p[j]) DP[i+1][j+1] = DP[i][j];
                else if(p[j]=='.') DP[i+1][j+1] = DP[i][j];
                else if(p[j]=='*'){
                    if(p[j-1]!=s[i] && p[j-1]!='.'){
                        DP[i+1][j+1] = DP[i+1][j-1];
                    }
                    else DP[i+1][j+1] = DP[i+1][j-1] || DP[i][j+1] || DP[i+1][j];
                }
            }
        }
        return DP[s.size()][p.size()];
    }
};
