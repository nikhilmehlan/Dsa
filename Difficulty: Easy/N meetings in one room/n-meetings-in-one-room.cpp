//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct meeting{
        int start;
        int end;
        int pos;
    };
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    // struct meeting{
    //     int start;
    //     int end;
    //     int pos;
    // }
    bool static comparator(struct meeting m1,meeting m2){
        if(m1.end<m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos<m2.pos) return true;
        return false;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        struct meeting meet[n];
        
        for(int i=0;i<n;i++){
            meet[i].start=start[i];
            meet[i].end=end[i];
            meet[i].pos=i+1;
        }
        sort(meet,meet+n,comparator);
        vector<int> answer;
        int cnt=1;
        int limit=meet[0].end;
        answer.push_back(meet[0].pos);
        for(int i=1;i<n;i++){
            if(meet[i].start>limit){
                cnt++;
                limit=meet[i].end;
            answer.push_back(meet[i].pos);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends