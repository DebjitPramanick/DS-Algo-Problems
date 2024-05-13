package Algo_Problems.Recursion.Medium;

/*
 * Given a number n, the task is to generate all possible n pairs of balanced parentheses.
 */

public class BalancedParenthesis {
    public static void main(String[] args) {
        solve(3, 3, "");
    }

    static void solve(Integer parenthesisToOpen, Integer parenthesisToClose, String res) {
        if (parenthesisToOpen == 0 && parenthesisToClose == 0) {
            System.out.println(res);
            return;
        }

        if (parenthesisToOpen > parenthesisToClose || parenthesisToOpen < 0 || parenthesisToClose < 0) {
            return;
        }

        res += "{";
        solve(parenthesisToOpen - 1, parenthesisToClose, res);
        res = res.substring(0, res.length() - 1);

        res += "}";
        solve(parenthesisToOpen, parenthesisToClose - 1, res);
        res = res.substring(0, res.length() - 1);
    }
}