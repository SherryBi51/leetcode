//1. Insert the words into the Trie. 
//2. Using depth-first search to scan all the possible words in the board, and check if it exists in the Trie;

class TrieNode{
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(){
        isKey = false;
        memset(children, NULL, sizeof(TrieNode*)*26);
    }
};

class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode *pNode = root;
        for(char ch: word){
            if(pNode->children[ch-'a']==NULL){
                TrieNode *pNew = new TrieNode();
                pNode->children[ch-'a'] = pNew;
            }
            pNode = pNode->children[ch-'a'];
        }
        pNode->isKey = true;
    }
    
    int search(string word){
        TrieNode *pNode = root;
        for(char ch: word){
            if(pNode->children[ch-'a']==NULL) return 0;
            else pNode = pNode->children[ch-'a'];
        }
        return (pNode->isKey)?1:-1;
    }
    
    /*
    bool startWith(string prefix){
        TrieNode *pNode = root;
        for(char ch: prefix){
            if(pNode->children[ch-'a']==NULL) return false;
            else pNode = pNode->children[ch-'a'];
        }
        return true;
    }
    */
};

class Solution {
public:
    void dfs(unordered_set<string>& existW, vector<vector<char>>& board, vector<vector<bool>>& visited, string &str, int x, int y, Trie trie){
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size()) return;
        if(visited[x][y]) return;
        
        str.push_back(board[x][y]);
        
        int res = trie.search(str);
        if(res==0){
            str.pop_back();
            return;
        }
        if(res==1) existW.insert(str);
        /*
        if(!trie.startWith(str)) return;
        
        if(trie.search(str)) existW.insert(str);
        */
        visited[x][y] = true;
        dfs(existW, board, visited, str, x-1, y, trie);
        dfs(existW, board, visited, str, x+1, y, trie);
        dfs(existW, board, visited, str, x, y-1, trie);
        dfs(existW, board, visited, str, x, y+1, trie);     
        visited[x][y] = false;
        str.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size()==0 || board[0].size()==0) return vector<string>();
        
        Trie trie;
        for(string w: words) trie.insert(w);

        int len1 = board.size();
        int len2 = board[0].size();
        vector<vector<bool>> visited(len1, vector<bool>(len2, false));
        unordered_set<string> existW;
        vector<string> res;
        string str = "";
        
        for(int i=0; i<len1; ++i){
            for(int j=0; j<len2; ++j){
                dfs(existW, board, visited, str, i, j, trie);
            }
        }
        
        for(auto it=existW.begin(); it!=existW.end(); ++it) res.push_back(*it);
        return res;
    }
};
