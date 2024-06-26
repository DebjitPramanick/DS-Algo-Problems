package DS_Problems.Stack;

import java.util.Stack;

public class ReverseStack {
    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < 5; i++)
            s.add(i);

        reverse(s);

        while (!s.empty()) {
            System.out.println(s.pop());
        }
    }

    static void reverse(Stack<Integer> s) {
        if (s.empty()) {
            return;
        }
        int top = s.pop();
        reverse(s);
        insert(s, top);
    }

    static void insert(Stack<Integer> s, int el) {
        if (s.empty()) {
            s.add(el);
            return;
        }

        int top = s.pop();
        insert(s, el);
        s.add(top);
    }
}
