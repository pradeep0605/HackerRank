#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#undef NULL
#define NULL (-1)

typedef struct {
    int left;
    int right;
} links;

links nodes[1025] = {{0,0}};

void print_inorder(int root) {
    if (root == NULL) {
        return;
    }
    
    print_inorder(nodes[root].left);
    cout << root << " ";
    print_inorder(nodes[root].right);
}

void transform_tree(int root, int cur_depth, int K) {
    if (root == NULL) {
        return;
    }
    if ( cur_depth % K == 0) {
        int temp = nodes[root].left;
        nodes[root].left = nodes[root].right;
        nodes[root].right = temp;
    }
    
    transform_tree(nodes[root].left, cur_depth + 1, K);
    transform_tree(nodes[root].right, cur_depth + 1, K);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    int Q;
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        int l, r;
        cin >> l >> r;
        nodes[i].left = l;
        nodes[i].right = r;
    }
    cin >> Q;
    for (int j = 0; j < Q; ++j) {
        int k = 0;
        cin >> k;
        transform_tree( /* root node */1, /*current depth */ 1, k);
        print_inorder(1);
        cout << endl;
    }
    return 0;
}

