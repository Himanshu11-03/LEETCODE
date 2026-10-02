class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;
        bool digitAfterExp = true;

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {
                seenDigit = true;

                if (seenExp)
                    digitAfterExp = true;
            }

            else if (s[i] == '.') {
                if (seenDot || seenExp)
                    return false;

                seenDot = true;
            }

            else if (s[i] == 'e' || s[i] == 'E') {
                if (seenExp || !seenDigit)
                    return false;

                seenExp = true;
                digitAfterExp = false;
            }

            else if (s[i] == '+' || s[i] == '-') {
                if (i != 0 &&
                    s[i - 1] != 'e' &&
                    s[i - 1] != 'E')
                    return false;
            }

            else {
                return false;
            }
        }

        return seenDigit && digitAfterExp;
    }
};