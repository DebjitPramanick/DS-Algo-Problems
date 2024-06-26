package DS_Problems.Stack;

import java.util.Stack;

/**
 * BalancedParenthesis
 */
public class BalancedParenthesis {
    public static void main(String[] args) {
        String s = "[{()]";
        solve(s);
    }

    public static void solve(String s) {
        Stack<Character> st = new Stack<>();
        boolean isValid = true;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '[' || s.charAt(i) == '(' || s.charAt(i) == '{') {
                st.add(s.charAt(i));
            } else if (s.charAt(i) == '}' && st.peek() != '{') {
                isValid = false;
                break;
            } else if (s.charAt(i) == ']' && st.peek() != '[') {
                isValid = false;
                break;
            } else if (s.charAt(i) == ')' && st.peek() != '(') {
                isValid = false;
                break;
            } else {
                st.pop();
            }
        }
        System.out.println(isValid);
    }
}