#include <stdint.h>
#include <stdio.h>
#include <stack>

using namespace std;

class Solution {
public:
    /**
    * @param s A string
    * @return whether the string is a valid parentheses
    */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> st;
        bool rs = true;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else if (s[i] == ')') {
                if (st.empty()) {
                    return false;
                }
                else {
                    char left = st.top();
                    st.pop();

                    if (left != '(') return false;
                }
            }
            else if (s[i] == ']') {
                if (st.empty()) {
                    return false;
                }
                else {
                    char left = st.top();
                    st.pop();

                    if (left != '[') return false;
                }
            }
            else {
                if (st.empty()) {
                    return false;
                }
                else {
                    char left = st.top();
                    st.pop();

                    if (left != '{') return false;
                }
            }
        }
        
        if (!st.empty()) return false;

        return true;
    }
};