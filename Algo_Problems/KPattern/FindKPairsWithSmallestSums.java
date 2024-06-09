package Algo_Problems.KPattern;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

/*
 * Find K Pairs with Smallest Sums
 * 
 * You are given two integer arrays nums1 and nums2 sorted in 
 * non-decreasing order and an integer k.
 * Define a pair (u, v) which consists of one element from the 
 * first array and one element from the second array.
 * Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with 
 * the smallest sums.
 */

public class FindKPairsWithSmallestSums {
    public static void main(String[] args) {
        int nums1[] = { 1, 7, 11 };
        int nums2[] = { 2, 4, 6 };
        solve(nums1, nums2, 2);
    }

    public static void solve(int nums1[], int nums2[], int k) {
        List<List<Integer>> resV = new ArrayList<>(); // Result list to store the pairs
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        // Push the initial pairs into the priority queue
        for (int x : nums1) {
            pq.offer(new int[] { x + nums2[0], 0 }); // The sum and the index of the second element in nums2
        }

        // Pop the k smallest pairs from the priority queue
        while (k > 0 && !pq.isEmpty()) {
            int[] pair = pq.poll();
            int sum = pair[0]; // Get the smallest sum
            int pos = pair[1]; // Get the index of the second element in nums2

            List<Integer> currentPair = new ArrayList<>();
            currentPair.add(sum - nums2[pos]);
            currentPair.add(nums2[pos]);
            resV.add(currentPair); // Add the pair to the result list

            // If there are more elements in nums2, push the next pair into the priority
            // queue
            if (pos + 1 < nums2.length) {
                pq.offer(new int[] { sum - nums2[pos] + nums2[pos + 1], pos + 1 });
            }

            k--; // Decrement k
        }

        for (List<Integer> nums : resV) {
            for (Integer num : nums) {
                System.out.print(num + " ");
            }
            System.out.println("");
        }
    }
}
