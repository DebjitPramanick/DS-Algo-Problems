package Algo_Problems.Backtracking;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

/*
 * An expression will be given which can contain open 
 * and close parentheses and optionally some characters, 
 * No other operator will be there in string. We need to 
 * remove minimum number of parentheses to make the input 
 * string valid. If more than one valid output are possible 
 * removing same number of parentheses then print all such 
 * output.  
 */

public class RemoveInvalidParenthesis {
    public static void main(String[] args) {
        solve("()())()");
    }

    static boolean isParenthesis(char c) {
        return ((c == '(') || (c == ')'));
    }

    static boolean isValidString(String str) {
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(')
                cnt++;
            else if (str.charAt(i) == ')')
                cnt--;
            if (cnt < 0)
                return false;
        }
        return (cnt == 0);
    }

    // method to remove invalid parenthesis
    static void solve(String str) {
        if (str.isEmpty())
            return;

        // visit set to ignore already visited string
        HashSet<String> visit = new HashSet<String>();

        // queue to maintain BFS
        Queue<String> q = new LinkedList<>();
        String temp;
        boolean level = false;

        // pushing given string as
        // starting node into queue
        q.add(str);
        visit.add(str);

        while (!q.isEmpty()) {
            str = q.peek();
            q.remove();
            if (isValidString(str)) {
                System.out.println(str);
                level = true;
            }
            if (level)
                continue;
            for (int i = 0; i < str.length(); i++) {
                if (!isParenthesis(str.charAt(i)))
                    continue;

                // Removing parenthesis from str and
                // pushing into queue,if not visited already
                temp = str.substring(0, i) + str.substring(i + 1);
                if (!visit.contains(temp)) {
                    q.add(temp);
                    visit.add(temp);
                }
            }
        }
    }
}
