class Solution {
public:
    unordered_map<string, int> FuncCount(string formula) {
        unordered_map<string, int> EleCount;
        stack<unordered_map<string, int>> stk;
        int n = formula.length();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                stk.push(EleCount);
                EleCount.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                if (count == 0)
                    count = 1;
                unordered_map<string, int> temp = EleCount;
                EleCount = stk.top();
                stk.pop();
                for (auto& p : temp) {
                    EleCount[p.first] += p.second * count;
                }
            } else {
                string element(1, formula[i++]);
                while (i < n && islower(formula[i])) {
                    element += formula[i++];
                }
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                if (count == 0)
                    count = 1;
                EleCount[element] += count;
            }
        }

        return EleCount;
    }

    string FuncResult(unordered_map<string, int>& EleCount) {
        vector<pair<string, int>> elements(EleCount.begin(),
                                           EleCount.end());
        sort(elements.begin(), elements.end());

        string result;
        for (auto& elem : elements) {
            result += elem.first;
            if (elem.second > 1) {
                result += to_string(elem.second);
            }
        }
        return result;
    }

    string countOfAtoms(string formula) {
        unordered_map<string, int> EleCount = FuncCount(formula);
        return FuncResult(EleCount);
    }
};
