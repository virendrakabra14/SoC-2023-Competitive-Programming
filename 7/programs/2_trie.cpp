#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    char val;
    int count;
    int endsHere;
    vector<TrieNode*> children;

    TrieNode(char c) {
        val = c;
        count = 0;
        endsHere = 0;

        children.resize(26);
        for(auto& child: children) {    // note "&"
            child = nullptr;
        }
    }
};

typedef TrieNode tn;

class Trie {

    tn* root;

public:

    Trie() {
        root = new tn('/');
    }

    ~Trie() {
        clear(root);
    }

    void clear(tn* node) {
        for(auto& child: node->children) {
            clear(child);
        }
        delete node;
    }

    void insert(string s) {
        int n = s.length();
        tn* curr = root;
        for (int i=0; i<n; i++) {
            if(curr->children[s[i]-'a'] == nullptr) {
                curr->children[s[i]-'a'] = new tn(s[i]);
            }
            curr = curr->children[s[i]-'a'];
            curr->count++;
        }
        curr->endsHere++;
    }

    int search(string s) {
        // returns count of string s in the Trie [including duplicates]
        // NOT just prefix, but complete string 's', ending too

        int n = s.length();
        tn* curr = root;
        for (int i=0; i<n; i++) {
            if(curr->children[s[i]-'a'] == nullptr) return 0;
            curr = curr->children[s[i]-'a'];
        }
        return curr->endsHere;
    }

    int prefix(string s) {
        // how many times 's' appears as prefix in the Trie

        int n = s.length();
        tn* curr = root;
        for (int i=0; i<n; i++) {
            if(curr->children[s[i]-'a']==nullptr) return 0;
            curr = curr->children[s[i]-'a'];
        }
        return curr->count;
    }

};

int main() {
    Trie* obj = new Trie();
    obj->insert("abcd");
    obj->insert("efghi");
    obj->insert("abcdef");
    obj->insert("fghij");
    cout << obj->search("abcd") << '\n';
    cout << obj->prefix("abc") << '\n';
}