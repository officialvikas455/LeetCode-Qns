class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        stack<set<string>> operands;
        stack<char> ops;

        auto apply_op = [&]() {
            auto right = operands.top(); operands.pop();
            auto left = operands.top(); operands.pop();
            char op = ops.top(); ops.pop();

            set<string> res;
            if (op == '*') { // Cartesian Product
                for (const string& l : left) {
                    for (const string& r : right) {
                        res.insert(l + r);
                    }
                }
            } else if (op == ',') { // Set Union
                res = left;
                res.insert(right.begin(), right.end());
            }
            operands.push(res);
        };

        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            // 1. Insert implicit '*' if necessary
            if (i > 0) {
                char prev = expression[i - 1];
                if ((isalpha(prev) || prev == '}') && (isalpha(c) || c == '{')) {
                    // Precedence: '*' > ','
                    while (!ops.empty() && ops.top() == '*') {
                        apply_op();
                    }
                    ops.push('*');
                }
            }

            // 2. Process current character
            if (isalpha(c)) {
                operands.push({string(1, c)});
            } else if (c == '{') {
                ops.push('{');
            } else if (c == ',') {
                // ',' has lowest precedence among operators (except '{')
                while (!ops.empty() && (ops.top() == '*' || ops.top() == ',')) {
                    apply_op();
                }
                ops.push(',');
            } else if (c == '}') {
                while (!ops.empty() && ops.top() != '{') {
                    apply_op();
                }
                ops.pop(); // Pop '{'
            }
        }

        // 3. Clear remaining operators
        while (!ops.empty()) {
            apply_op();
        }

        // Convert final set to vector
        return vector<string>(operands.top().begin(), operands.top().end());
    }
};