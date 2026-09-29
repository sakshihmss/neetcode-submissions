struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(): isEndOfWord(false){
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        int n = word.length();
        for(int i=0;i<n;i++)
        {
            int index = word[i] - 'a';
            if(curr->children[index] == NULL)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        int n = word.length();
        for(int i=0;i<n;i++)
        {
            int index = word[i] - 'a';
            if(curr->children[index] == NULL)
                return false;
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int n = prefix.length();
        for(int i=0;i<n;i++)
        {
            int index = prefix[i] - 'a';
            if(curr->children[index] == NULL)
                return false;
            curr = curr->children[index];
        }
        return true;
    }
};
