//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int find(int a[], int x);
void unionSet(int a[], int x, int z);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            if (s == "UNION") {
                int z, x;
                cin >> x >> z;
                unionSet(a, x, z);
            } else {
                int x;
                cin >> x;
                int parent = find(a, x);
                cout << parent << " ";
            }
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends

// Global rank array

int find(int par[], int x) {
    if (x == par[x]) return x;
    return par[x] = find(par, par[x]); // Path compression
}

void unionSet(int par[], int x, int z) {
    int parentX = find(par, x);
    int parentZ = find(par, z);
    if (parentX != parentZ) {
        par[parentX] = parentZ; // Make parent of x point to parent of z
    }
}
