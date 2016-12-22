/* Solution for problem : https://www.hackerrank.com/challenges/bfsshortreach
 * One testcase is failing and other is timingout
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node 
{
	public:
	bool is_visited;
	node *adjnodes[1001];
	node () {
		is_visited = 0;
		for(int i = 0; i < 1000; ++i) {
			adjnodes[i] = NULL;
		}
	}
};

inline int get_distance(int src, int dest, int n, int arr[1001][1001], char visited[1001]) {
    visited[src] = 1;
    //cout << "Inside node " << src << " arr[" << src << "][" << dest << "] " << arr[src][dest] << endl;
    if (arr[src][dest] !=  0) {
    	if (print)
        cout << "Inside node " << src << " returning " << arr[src][dest] << endl;
        visited[src] = 0;
        return arr[src][dest];
    }
    
    unsigned int smallest_count = -1;
    int through_node = 0;
    for (int i = 1; i<= n; ++i) {
        if (i == src) {
            continue;
        }
        int res;
        if ((!visited[i]) && arr[src][i] > 0) {
        	if (print)
               cout << "Inside node " << src << " Visiting " << i << endl;
            res = get_distance(i, dest, n, arr, visited);
            if (res != -1 && res < smallest_count) {
                smallest_count = res;
                through_node = i;
            }
        }
    }
    visited[src] = 0;
    int ret = -1;
    if (smallest_count != -1) {
        arr[src][dest] = arr[dest][src] = smallest_count + arr[src][through_node];
         
    } else {
    	arr[src][dest] = arr[dest][src] = -1;
    }
    ret = arr[src][dest];
    
    if (print)
	    cout << "Inside node " << src << " returning " << ret << endl;
    
    return ret;
}

inline void handle_testcase(int n, int m)
{
    int arr[1001][1001] = {{0}, {0}};    
    char visited[1001]= {0};
    int start_node = 0;
    for(int itr = 0 ; itr < m; ++itr) {
        int i , j;
        cin >> i >> j;
        //cout << i << "--" << j << ";" << endl;
        arr[i][j] = arr[j][i] = 6; // Undirected graph.
    }
    cin >> start_node;
   // cout << "start_node = " << start_node << endl;
    for (int i = n; i >= 1; --i) {
        if (i != start_node) {
            //cout << "DISTANCE BETWEEN " << i << " AND " << start_node << endl;
            if (arr[start_node][i] == 0) {
                get_distance(i, start_node, n,  arr, visited);
            } 
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (start_node != i)
            cout << arr[start_node][i] << " ";
    }
    cout << endl;
 /*
    for (int i = 0; i < n; ++i) {
        for(int j = 0 ; j < n; ++j) {
            cout << arr[i][j] << " ";
            #if 0
            if (arr[i][j]) {
                cout << "(" << i << ", " << j <<") = " << arr[i][j] << " | ";
            }
            #endif
        }   
        cout << endl;
    }
    */
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        handle_testcase(n, m);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

