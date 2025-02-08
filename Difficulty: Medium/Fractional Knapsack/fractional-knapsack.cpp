//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented

struct Item {
    int value;
    int weight;
};

// Comparator function to sort items by value-to-weight ratio in descending order
bool compare(Item a, Item b) {
    return (double(a.value) / a.weight) > (double(b.value) / b.weight);
}

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items(n);
        
        // Filling the items vector
        for (int i = 0; i < n; i++) {
            items[i] = {val[i], wt[i]};
        }

        // Sorting items by value-to-weight ratio
        sort(items.begin(), items.end(), compare);
        
        double totalValue = 0.0;

        for (int i = 0; i < n; i++) {
            if (capacity >= items[i].weight) {  // Take full item
                totalValue += items[i].value;
                capacity -= items[i].weight;
            } else {  // Take fractional part
                totalValue += (double(items[i].value) / items[i].weight) * capacity;
                break; // Knapsack is full
            }
        }
        return totalValue;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends