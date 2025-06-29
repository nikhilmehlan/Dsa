class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> temp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                temp[nums2[i]]=-1;
            }
            else{
                temp[nums2[i]]=st.top();

            }
        st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto it:nums1){
            ans.push_back(temp[it]);
        }
        return ans;
    }
};