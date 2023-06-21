/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isterminal;

    TrieNode(char data){
        this->data = data;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isterminal = false;
    }
};


class Trie {

public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */

    void insertintrie(TrieNode* root, string word){
        if(word.length() == 0){
            root->isterminal = true;
            return;
        }

        int index = word[0]-'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertintrie(child, word.substr(1));
    }

    void insert(string word) {
        insertintrie(root, word);
        return;
    }

    /** Returns if the word is in the trie. */
    bool searchintrie(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isterminal;
        }

        int index = word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL)
            child = root->children[index];
        else
            return false;
        
        return searchintrie(child,word.substr(1));
    }

    bool search(string word){
        return searchintrie(root,word);
    }


    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* rroot = root;
        for(auto i: prefix){
            char x = i-'a';
            if(rroot->children[x]!=NULL){
                rroot = rroot->children[x];
            }else return false;
        }
        return rroot!=NULL;
    }
};