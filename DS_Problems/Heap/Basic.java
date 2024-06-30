package DS_Problems.Heap;

import java.util.Collections;
import java.util.PriorityQueue;

// Find k-th smallest and k-th largest elements

public class Basic {
    public static void main(String[] args) {
        int nums[] = { 7, 10, 4, 3, 20, 15 };
        solve(nums, 3);
    }

    public static void solve(int nums[], int k) {
        PriorityQueue<Integer> min = new PriorityQueue<>();
        PriorityQueue<Integer> max = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < nums.length; i++) {
            min.add(nums[i]);
            max.add(nums[i]);

            if (min.size() > k) {
                min.poll();
            }
            if (max.size() > k) {
                max.poll();
            }
        }

        System.out.println(max.peek());
        System.out.println(min.peek());
    }
}
