package Algo_Problems.KPattern;

import java.util.PriorityQueue;

/*
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 */

public class KthLargestElement {
    public static void main(String[] args) {
        int nums[] = { 3, 2, 1, 5, 6, 4 };
        solve(nums, 4);
    }

    public static void solve(int nums[], int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 0; i < nums.length; i++) {
            pq.add(nums[i]);
            if (pq.size() > k) {
                pq.poll();
            }
        }

        System.out.println("Element is: " + pq.peek());
    }
}
