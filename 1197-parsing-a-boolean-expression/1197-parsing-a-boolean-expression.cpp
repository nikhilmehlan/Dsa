class Solution {
public:
    bool parseBoolExpr(string expression) {
        return eval(expression, 0, expression.size() - 1);
    }

private:
    bool eval(const string& exp, int start, int end) {
        if (start == end) {
            return exp[start] == 't';
        }

        char op = exp[start];
        vector<bool> results;
        int balance = 0;
        int i = start + 2; // skip the operator and opening '('

        for (int j = i; j < end; ++j) {
            if (exp[j] == '(') balance++;
            else if (exp[j] == ')') balance--;
            else if (exp[j] == ',' && balance == 0) {
                results.push_back(eval(exp, i, j - 1));
                i = j + 1;
            }
        }
        // last subexpression
        results.push_back(eval(exp, i, end - 1));

        if (op == '!') return !results[0];
        if (op == '&') {
            for (bool val : results) {
                if (!val) return false;
            }
            return true;
        }
        if (op == '|') {
            for (bool val : results) {
                if (val) return true;
            }
            return false;
        }

        return false; // shouldn't reach here
    }
};
