//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        vector<tuple<int, int, int>> jobs;
        int maxd = -1;

        // Store job details
        for (int i = 0; i < id.size(); i++) {
            jobs.emplace_back(profit[i], deadline[i], id[i]);
        }

        // Sort jobs based on profit in descending order
        sort(jobs.rbegin(), jobs.rend());

        // Find maximum deadline
        for (auto &job : jobs) {
            maxd = max(maxd, get<1>(job));
        }

        vector<int> slot(maxd + 1, -1);
        int cnt = 0, total = 0;

        // Schedule jobs
        for (auto &job : jobs) {
            int prof = get<0>(job);
            int dead = get<1>(job);
            int jobid = get<2>(job);

            for (int j = dead; j > 0; j--) { // Corrected loop condition
                if (slot[j] == -1) { // If slot is free
                    slot[j] = jobid;
                    cnt++;
                    total += prof;
                    break;
                }
            }
        }
        return {cnt, total};
    }
};



//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends