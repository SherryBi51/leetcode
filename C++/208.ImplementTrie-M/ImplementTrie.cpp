//First, I defined a TrieNode data structure, representing a letter. The field "isKey" is to label whether the string starting from the root to the current node is a word or a prefix. And since only lowercase "a-z" is consisted, so a TrieNode has at most 26 children, and I stored them in an array. The children[j] represents the char 'a'+j.
class TrieNode{
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(){
        isKey = false;
        memset(children, NULL, sizeof(TrieNode*)*26);
    }
};
class Trie {
//In the class Trie, we need an root TrieNode, and I think it is better to be defined as a private member.
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    //To insert a word, the basic idea is to create a TrieNode for each letter of the word. 
    /** Inserts a word into the trie. */
    void insert(string word) {
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
    
    //To search a word, the basic idea is to find the TrieNode corresponding to each letter of the word, and the last TrieNode should be marked is Key.
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *pNode = root;
        for(char ch: word){
            if(pNode->children[ch-'a']==NULL) return false;
            else pNode = pNode->children[ch-'a'];
        }
        return pNode->isKey;
    }
    
    //To search a prefix, it is the same as searching a word, but the last TrieNode do not need to be marker as Key.
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *pNode = root;
        for(char ch: prefix){
            if(pNode->children[ch-'a']==NULL) return false;
            else pNode = pNode->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
