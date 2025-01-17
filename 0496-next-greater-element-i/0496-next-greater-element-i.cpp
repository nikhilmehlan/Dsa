class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int,int>> temp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                temp.push_back({nums2[i],-1});
            }
            else{
                temp.push_back({nums2[i],st.top()});
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(auto it:temp){
                if(nums1[i]==it.first){
                    ans.push_back(it.second);
                }
            }
        }
        return ans;
    }
};