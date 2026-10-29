class Solution {
public:
    int calculate(string s) {
        stack<int> st;

        long long result = 0;
        long long num = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {

            if (isdigit(s[i])) {
                num = 0;

                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                result += sign * num;
                num = 0;
                i--;
            }

            else if (s[i] == '+') {
                sign = 1;
            }

            else if (s[i] == '-') {
                sign = -1;
            }

            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (s[i] == ')') {
                int previousSign = st.top();
                st.pop();

                long long previousResult = st.top();
                st.pop();

                result = previousResult + previousSign * result;
                sign = 1;
            }
        }

        return (int)result;
    }
};