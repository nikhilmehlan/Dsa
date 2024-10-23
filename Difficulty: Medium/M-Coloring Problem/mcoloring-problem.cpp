//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to check if it is safe to assign the color to the current node
    bool isSafe(int node, vector<int>& color, vector<vector<int>>& graph, int col) {
        for (int neighbor : graph[node]) {
            if (color[neighbor] == col) {
                return false;  // If the neighbor has the same color, it's not safe
            }
        }
        return true;
    }

    // Backtracking function to try coloring the graph
    bool graphColoringUtil(int node, int m, vector<int>& color, vector<vector<int>>& graph, int v) {
        if (node == v) {
            return true;  // All vertices have been assigned a color
        }
        
        // Try assigning colors from 1 to m
        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, graph, col)) {
                color[node] = col;  // Assign color `col` to vertex `node`
                
                // Recur to assign colors to the rest of the vertices
                if (graphColoringUtil(node + 1, m, color, graph, v)) {
                    return true;
                }

                // Backtrack if coloring does not lead to a solution
                color[node] = 0;
            }
        }
        
        return false;  // If no color can be assigned, return false
    }

    // Main function to check if graph can be colored with at most m colors
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<vector<int>> graph(v);
        
        // Build the adjacency list from the edges
        for (auto edge : edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);  // Undirected graph
        }
        
        vector<int> color(v, 0);  // Color array initialized to 0 (no color assigned)
        
        // Start the coloring process from the first vertex (vertex 0)
        return graphColoringUtil(0, m, color, graph, v);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << endl; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends