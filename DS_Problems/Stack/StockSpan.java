package DS_Problems.Stack;

import java.util.Stack;

// The stock span problem is a financial problem 

// where we have a series of n daily price quotes 
// for a stock and we need to calculate span of 
// stock’s price for all n days. The span Si of 
// the stock’s price on a given day i is defined 
// as the maximum number of consecutive days just 
// before the given day, for which the price of the 
// stock on that day is less than or equal 
// to the price on current day. For example, if 
// an array of 7 days prices is given as 
// {100, 80, 60, 70, 60, 75, 85}, then the span 
// values for corresponding 7 days are 
// {1, 1, 1, 2, 1, 4, 6} 

// It's a variant of next greater element
public class StockSpan {
    public static void main(String[] args) {
        int prices[] = { 100, 80, 60, 70, 60, 75, 85 };
        solve(prices);
    }

    public static void solve(int prices[]) {
        Stack<int[]> s = new Stack<>();
        int ans[] = new int[prices.length];
        s.push(new int[] { prices[0], 0 });
        ans[0] = 1;

        for (int i = 1; i < prices.length; i++) {
            ans[i] = 1;
            if (s.isEmpty()) {
                s.add(new int[] { prices[i], i });
                continue;
            }

            while (!s.isEmpty() && s.peek()[0] <= prices[i]) {
                ans[i] += ans[s.peek()[1]];
                s.pop();
            }

            s.push(new int[] { prices[i], i });
        }

        for (int num : ans) {
            System.out.print(num + " ");
        }
    }

}
