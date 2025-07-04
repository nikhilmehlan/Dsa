class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> idx;
        idx.push(-1);
        int max_len = 0;
        for(int i =0;i<s.size();++i){
            if(s[i] == '('){
                idx.push(i);
            }else{
                idx.pop();
                if(idx.empty()){
                    idx.push(i);
                }
                max_len = max(max_len, i-idx.top());
            }
            
        }
        return max_len;
    }
};
/*
)))(())
[-1 3 4 ]
")()())"
-1 0 1 

*/