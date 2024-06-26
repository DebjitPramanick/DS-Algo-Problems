package DS_Problems.Stack;

import java.util.Stack;

// Given an array, print the Next Greater Element (NGE) 
// for every element. The Next greater Element for an 
// element x is the first greater element on the right 
// side of x in the array. Elements for which no greater 
// element exist, consider the next greater element as -1.

public class NextGreaterElement {
    public static void main(String[] args) {
        int nums[] = { 4, 5, 2, 25 };
        solve(nums);
    }

    public static void solve(int nums[]) {
        Stack<Integer> s = new Stack<>();

        s.push(nums[0]);

        for (int i = 1; i < nums.length; i++) {
            if (s.empty()) {
                s.add(nums[i]);
                continue;
            }

            while (!s.empty() && s.peek() < nums[i]) {
                System.out.println(s.peek() + " -> " + nums[i]);
                s.pop();
            }

            s.add(nums[i]);
        }

        while (!s.empty()) {
            System.out.println(s.pop() + " -> -1");
        }
    }
}
