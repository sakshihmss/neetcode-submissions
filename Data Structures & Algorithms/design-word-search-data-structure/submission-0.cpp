struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode():isEndOfWord(false){
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        int n = word.length();
        for(int i=0;i<n;i++)
        {
            int idx = word[i] - 'a';
            if(curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
        return;
    }

    bool search(TrieNode* curr, string word)
    {
        int n = word.length();
        for(int i=0;i<n;i++)
        {
            if(word[i] != '.')
            {
                int idx = word[i] - 'a';
                if(curr->children[idx] == NULL)
                    return false;
                curr = curr->children[idx];
            }
            else
            {
                for(int j=0;j<26;j++)
                {
                    if(curr->children[j] && search(curr->children[j], word.substr(i+1)))
                        return true;
                }
                return false;
            }
        }
        return curr->isEndOfWord;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        return search(curr, word);
    }
};
