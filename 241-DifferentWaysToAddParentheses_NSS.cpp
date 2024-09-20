class Solution {
public:
    map<pair<int, int>, vector<int>> cache;

    vector<int> diffWaysToCompute(string expression) {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        vector<int> exp;
        int idx = 0;
        expression += "+";
        while (idx < expression.size())  {
            char c = expression[idx];
            char c1 = expression[idx + 1];
            char c2 = expression[idx + 2];
            if (c == '+') { exp.push_back(-1); idx += 1; }
            else if (c == '-') { exp.push_back(-2); idx += 1; }
            else if (c == '*') { exp.push_back(-3); idx += 1; }
            else if (c1 == '+' || c1 == '-' || c1 == '*') {
                exp.push_back(c - 48);
                idx += 1;
            }
            else if (c2 == '+' || c2 == '-' || c2 == '*') {
                int _c = c - 48;
                int _c1 = c1 - 48;
                exp.push_back(_c*10 + _c1);
                idx += 2;
            }
        }

        exp.pop_back();

        return solve(exp, 0, exp.size() - 1);
    }

    vector<int> solve(vector<int>& exp, int start, int end) {
        vector<int> ans;

        if (start == end) {
            ans.push_back(exp[start]);
            return ans;
        }

        for (int i = start + 1; i <= end; i += 2) {
            if (cache[{start, i - 1}].size() == 0)
                cache[{start, i - 1}] = solve(exp, start, i - 1);
            if (cache[{i + 1, end}].size() == 0)
                cache[{i + 1, end}] = solve(exp, i + 1, end);

            vector<int> lefts = cache[{start, i - 1}];
            vector<int> rights = cache[{i + 1, end}];
            int op = exp[i];
            for (auto left : lefts) {
                for (auto right : rights) {
                    if (op == -1) ans.push_back(left + right);
                    else if (op == -2) ans.push_back(left - right);
                    else if (op == -3) ans.push_back(left * right);
                }
            }
        }

        return ans;
    }
};
