class Trie {
public:
    char data;
    Trie* children[26];
    bool isTerminal;
    Trie* root;  // Declare root as a class member

    // Constructor for Trie nodes
    Trie(char d) {
        this->data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        root = nullptr;  // Initialize root to nullptr for non-root nodes
    }

    // Constructor for the main Trie object
    Trie() {
        root = new Trie('\0');  // Initialize the root node with null character
    }

    void inserthelper( Trie* node, string word) {

        //Base case
        if(word.length()==0){
            node->isTerminal = true;
            return;
        }

        char ch = word[0];
        int index = ch-'a';
        Trie* child;

        if(node->children[index]!=NULL){
            child = node->children[index];
        }else{
            //make new node child with data as ch
            child = new Trie(ch);
            node->children[index] = child;
    
        }

        //recursion
        inserthelper(child,word.substr(1));
        
    }
    
    
     void insert(string word) {
        inserthelper(root,word);
    }

    bool searchhelper(Trie* node, string word){
         if(word.length()==0){
            return node->isTerminal;
        }

        char ch = word[0];
        int index = ch-'a';
        Trie* child;

        if(node->children[index]!=NULL){
            child = node->children[index];     
        }
        else{
            return false;
        }
           return searchhelper(child,word.substr(1));
    }

    
    bool search(string word) {
        return searchhelper(root,word);
    }

    bool startsWithHelper(Trie* node, string prefix) {
    if (prefix.length() == 0) {
        return true;
    }

    char ch = prefix[0];
    int index = ch - 'a';

    if (node->children[index] == NULL) {
        return false;
    }

    // Recursive call for the next character
    return startsWithHelper(node->children[index], prefix.substr(1));
}

    
    bool startsWith(string prefix) {

        return startsWithHelper(root, prefix);

    }
};

    

        
 
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
