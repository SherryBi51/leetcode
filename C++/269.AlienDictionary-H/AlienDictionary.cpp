//We can treat it as a topological sort problem of a graph. In this graph, we have at most 26 vertices. And the edge represent the order of two characters. 
//If w is ahead of r, then there is a edge from w to r, and the in-degree of r should plus 1
//After we construct the graph, we iteratively remove the vertices whose in-degree is zero. 
//And finally, if we have remove all the vertices, then we find the order of this dictionary.


class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<int>> graph(26, vector<int>(26,0));
        vector<int> showed(26,0);
        vector<int> in(26, 0);
        queue<int> vertices;
        string dic = "";
        string word1, word2;
        int len;
        
        //showed up
        //There may be some characters, they showed up but we don't know which character is ahead of it.
        for(string word: words){
            for(char ch: word){
                showed[ch-'a'] = 1;
            }
        }
        
        //BuildGraph
        for(int i=1; i<words.size(); ++i){
            word1 = words[i-1];
            word2 = words[i];
            len = min((int)word1.size(), (int)word2.size());
            for(int j=0; j<len; ++j){
                if(word1[j]==word2[j]) continue;
                else{
                    if(graph[word1[j]-'a'][word2[j]-'a']==0){
                        graph[word1[j]-'a'][word2[j]-'a'] = 1;
                        in[word2[j]-'a']++;
                    }
                    break;
                }
            }
        }
        
        //Topological Sort
        for(int i=0; i<26; ++i){
            if(showed[i]==1 && in[i]==0)
                vertices.push(i);
        }
        while(!vertices.empty()){
            auto cur = vertices.front();
            vertices.pop();
            dic.push_back('a'+cur);
            for(int i=0; i<26; ++i){
                if(graph[cur][i]==1){
                    in[i]--;
                    if(in[i]==0) vertices.push(i);
                }
            }
        }
        
        //Check circle
        for(int i=0; i<26; ++i){
            if(in[i]>0) return "";
        }
        return dic;
    }
};
