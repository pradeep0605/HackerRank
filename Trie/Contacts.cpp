/* This Solution is for the problem :
https://www.hackerrank.com/challenges/contacts

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <cstring>

using namespace std;

class TrieNode {
    public:
        char data;
        bool isWord;
        int wordCount;
        TrieNode* child[26];
        TrieNode() {
            data = '\0';
            wordCount = 0;
            isWord = false;
            std::memset(child, 0, sizeof(TrieNode*) * 26);
            for(int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
        
        TrieNode(char data, bool isWord = false) {
            this->data = data;
            this->isWord = isWord;
            wordCount = 0;
 	        std::memset(child, 0, sizeof(TrieNode*) * 26);
            /*
            for(int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            */
        }
};
class Trie {
    public:
       TrieNode *root;
       Trie() {
           root = new TrieNode();
       }
    
    void insertString(string s) {
        TrieNode *temp = root;
        if (s == "") {
        	return;
        }
        root->wordCount++;
        for(int i = 0; i < s.length(); ++i) {
            if (temp->child[s[i] - 'a'] == NULL) {
                TrieNode *n = new TrieNode(s[i]);
                temp->child[s[i] - 'a'] = n;            
                temp = n;
			    temp->wordCount++;
                continue;
            } else {
                temp = temp->child[s[i] - 'a'];
  			    temp->wordCount++;

            }
        }
        temp->isWord = true;
    }
    
    inline TrieNode * traverse(string s) {
        TrieNode *temp = root;
        for(int i = 0; i < s.length(); ++i) {
            if(temp == NULL || temp->child[s[i] - 'a'] == NULL)   {
                return NULL;
            } else {
                temp = temp->child[s[i] - 'a'];
            }
        }
        return temp;
    }
    int countSubtree(TrieNode *root) {
        if (root == NULL) {
            return 0;
        }
        
        int count = 0;
        if (root->isWord) {
            count++;
        }
        for(int i = 0; i < 26; ++i) {
            if (root->child[i] != NULL) {
                //cout << "calling countSubtree " << root->child[i]->data <<
                //endl;
                count += countSubtree(root->child[i]);
            }
        }
        return (count);
    }
    
    int findPartial(string s) {
        TrieNode *partialRoot = traverse(s);
        if (partialRoot == NULL) {
            return 0;
        }
        
        if (partialRoot != 0)
        	return partialRoot->wordCount;
    
        return countSubtree(partialRoot);
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    string op, val;
    Trie tree = Trie();
    while (n--) {
        cin >> op >> val;
        if (op == "add") {
            tree.insertString(val);
        } else if (op == "find") {
            cout << tree.findPartial(val) << endl;
        }
    }
    return 0;
}

