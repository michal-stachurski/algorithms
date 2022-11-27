#include <cstring>
typedef unsigned int uint;

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
    void add(const char* s) {
        node* v = root;
        for (uint i = 0; i < strlen(s); i++) {
            if (v->children[s[i] - 'a'] == nullptr) {
                v->children[s[i] - 'a'] = new node();
            }
            v = v->children[s[i] - 'a'];
        }
        v->end = true;
    }
    bool test(const char* s) {
        node* v = root;
        for (uint i = 0; i < strlen(s); i++) {
            if (v->children[s[i] - 'a'] == nullptr) {
                return false;
            }
            v = v->children[s[i] - 'a'];
        }
        return v->end;
    }
};
