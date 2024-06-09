package Algo_Problems.KPattern;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

/*
 * 703. Kth Largest Element in a Stream
 * 767. Reorganize String
 * 1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
 * 378. Kth Smallest Element in a Sorted Matrix
 * 719. Find K-th Smallest Pair Distance
 * 2040. Kth Smallest Product of Two Sorted Arrays
 * 264. Ugly Number II
 * 263. Ugly Number
 * 502. IPO
 * 
 * 
 * Given an integer array nums and an integer k, return the k most frequent elements. 
 * You may return the answer in any order.
 */

public class FindFirstKFrequentElements {
    public static void main(String[] args) {
        int nums[] = { 1, 1, 1, 2, 2, 3 };
        int k = 2;
        solve(nums, k);
    }

    static void solve(int nums[], int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            pq.add(entry);
            if (pq.size() > k) {
                pq.poll();
            }
        }

        while (!pq.isEmpty()) {
            System.out.print(pq.poll().getKey() + " ");
        }
        System.out.println("");
    }
}
