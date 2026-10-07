#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> validStrings;
        if (s.empty()) return validStrings;

        queue<string> pending;
        unordered_set<string> visited;

        pending.push(s);
        visited.insert(s);

        bool foundAtCurrentDepth = false;

        while (!pending.empty()) {
            string curr = pending.front();
            pending.pop();

            if (isValid(curr)) {
                validStrings.push_back(curr);
                foundAtCurrentDepth = true;
            }
            if (foundAtCurrentDepth) continue;

            for (int i = 0; i < curr.length(); ++i) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                string nextState = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.find(nextState) == visited.end()) {
                    visited.insert(nextState);
                    pending.push(nextState);
                }
            }
        }

        return validStrings;
    }

private:
    bool isValid(const string& str) {
        int balance = 0;
        for (char ch : str) {
            if (ch == '(') {
                balance++;
            } else if (ch == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }
};