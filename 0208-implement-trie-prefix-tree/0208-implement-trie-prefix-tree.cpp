class Trie {
public:
    Trie* children[26] = {};
    bool isEndWord = false;

    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char& c : word) {
            int idx = c - 'a';
            Trie* child = node->children[idx];
            if (!child) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEndWord = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char& c : word) {
            int idx = c - 'a';
            Trie* child = node->children[idx];
            if (!child) {
                return false;
            }
            node = child;
        }
        return node->isEndWord;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (char& c : prefix) {
            int idx = c - 'a';
            Trie* child = node->children[idx];
            if (!child) {
                return false;
            }
            node = child;
        }
        return true;
    }
};