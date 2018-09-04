//This problem is an application of the Trie data structure. 
//First, I defined a TrieNode data structure
//The field "isKey" is to label whether the string starting from root to the current node is a key. In this problem, only lowercase "a-z" is considered, so a TrieNode can have at most 26 children. I store them in an array children[0:26], children[j] represents the char 'a'+j.  

class TrieNode{
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(){
        isKey = false;
        memset(children, NULL, sizeof(TreeNode*)*26);
    }
};

class WordDictionary {
private:
    // The root is defined as a private member.
    TrieNode *root;
public:    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    //Add a word: the basic idea is to create a TrieNode corresponding to each letter of the word. And when we done, lable the last TrieNode as a key.
    void addWord(string word) {
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    //Search a word: The basic idea is to find each TireNode corresponding to the letter of the word. The critical part is how to deal with the dot. So, each time we reach a dot, just tranverse all the children of the current node, and recursively search the remaining substring of the word starting from that children. So I designed a helper function "helpQuery" for word search in a string with a starting position and a starting TrieNode. 
    bool search(string word) {
        return helpQuery(word, 0, root);
    }
    
    bool helpQuery(string &word, int start, TrieNode* pNode){
        for(int i=start; i<word.size(); ++i){
            if(word[i]=='.'){
                for(int j=0; j<26; ++j){
                    if(pNode->children[j] && helpQuery(word, i+1, pNode->children[j])) return true;
                }
                return false;
            }
            else{
                if(pNode->children[word[i]-'a']!=NULL){
                    pNode = pNode->children[word[i]-'a'];
                }
                else return false;
            }
        }
        return pNode->isKey;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
