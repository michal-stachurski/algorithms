// Trie data structure
#include <string>

class trie {
private:
    struct node {
        bool end;
        node* children[26];
    };
    node* root;

public:
    void init() {
        root = new node();
    }
    void add(const std::string& s) {
        node* v = root;
        for (const char& c : s) {
            if (v->children[c - 'a'] == nullptr) {
                v->children[c - 'a'] = new node();
            }
            v = v->children[c - 'a'];
        }
        v->end = true;
    }
    bool test(const std::string& s) {
        node* v = root;
        for (const char& c : s) {
            if (v->children[c - 'a'] == nullptr) {
                return false;
            }
            v = v->children[c - 'a'];
        }
        return v->end;
    }
};
