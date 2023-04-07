#include <cstdio>
#include <cstdint>
#include <utility>
#include <queue>
#include <string>

const std::pair<char, double> letters[] {
    {'E', 11.1607},
    {'A', 8.4966},
    {'R', 7.5809},
    {'I', 7.5448},
    {'O', 7.1635},
    {'T', 6.9509},
    {'N', 6.6544},
    {'S', 5.7351},
    {'L', 5.4893},
    {'C', 4.5388},
    {'U', 3.6308},
    {'D', 3.3844},
    {'P', 3.1671},
    {'M', 3.0129},
    {'H', 3.0034},
    {'G', 2.4705},
    {'B', 2.0720},
    {'F', 1.8121},
    {'Y', 1.7779},
    {'W', 1.2899},
    {'K', 1.1016},
    {'V', 1.0074},
    {'X', 0.2902},
    {'Z', 0.2722},
    {'J', 0.1965},
    {'Q', 0.1961}
};

double freq[256];
double sum, avg;

struct tree {
    struct node {
        node* left;
        node* right;
        char c;

        node(char letter = 0) {
            left = right = nullptr;
            c = letter;
        }
    };
    
    double weight;
    node* root;

    tree(char letter, double frequency) {
        root = new node(letter);
        weight = frequency;
    }
    tree(const tree& s, const tree& t) {
        weight = s.weight + t.weight;

        root = new node();
        root->left = s.root;
        root->right = t.root;
    }

    void dfs(node* v) const {
        static std::string code;
        if (v == nullptr) {
            return;
        }
        if (v->c != 0) {
            printf("%c: %s (%lu)\n", v->c, code.c_str(), code.size());
            sum += code.size();
            avg += (double)code.size() * freq[v->c];
        }
        code.push_back('0');
        dfs(v->left);
        code.pop_back();
        code.push_back('1');
        dfs(v->right);
        code.pop_back();
    }
    void print() const {
        dfs(root);
    }
};

bool operator<(const tree& s, const tree& t) {
    return s.weight > t.weight;
}

int main() {
    std::priority_queue<tree> forest;
    for (auto& letter : letters) {
        forest.emplace(letter.first, letter.second);
        freq[letter.first] = letter.second / 100.0d;
    }

    while (forest.size() > 1) {
        tree s = forest.top(); forest.pop();
        tree t = forest.top(); forest.pop();

        forest.emplace(s, t);
    }

    forest.top().print();

    printf("%0.6lf\n", sum / 26);
    printf("%0.6lf\n", avg);
}
