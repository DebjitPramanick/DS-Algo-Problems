package DS_Problems.Stack;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

// Given an array, for each element find the value of the nearest 
// element to the right which is having a frequency greater than as 
// that of the current element. If there does not exist an answer for 
// a position, then make the value ‘-1’. 

public class NextGreaterFreqElement {
    public static void main(String[] args) {
        int nums[] = { 1, 1, 2, 3, 4, 2, 1 };
        solve(nums);
    }

    public static void solve(int nums[]) {
        Map<Integer, Integer> mp = new HashMap<>();
        Stack<Integer> s = new Stack<>();

        for (int num : nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        s.push(nums[0]);

        for (int i = 1; i < nums.length; i++) {
            if (s.empty()) {
                s.push(nums[i]);
                continue;
            }

            while (!s.empty() && mp.get(s.peek()) < mp.get(nums[i])) {
                System.out.println(s.peek() + " -> " + nums[i]);
                s.pop();
            }

            s.add(nums[i]);
        }

        while (!s.empty()) {
            System.out.println(s.pop() + " -> " + -1);
        }

    }
}
