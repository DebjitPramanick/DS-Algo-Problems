package Algo_Problems.KWayMerge;

import java.util.PriorityQueue;

/*
 * The k-way merge pattern involves merging k sorted arrays into a single sorted array.
 * It exploits the sorted input to achieve merged order efficiently.
 * 
 * Use k-way merge when:
 * - You need to combine multiple sorted arrays or lists
 * - Finding the kth smallest/largest element in sorted arrays
*/

class HeapItem {
    int val;
    int list[];
    int nextItemIdx;

    HeapItem(int val, int list[], int nextItemIdx) {
        this.val = val;
        this.list = list;
        this.nextItemIdx = nextItemIdx;
    }
}

public class KWayMerge {
    public static void main(String[] args) {
        int arr[][] = { { 2, 6, 12, 34 },
                { 1, 9, 20, 1000 },
                { 23, 34, 90, 2000 } };
        int k = arr.length;
        int n = arr[0].length;
        solve(arr, k, n);

    }

    public static void solve(int lists[][], int k, int n) {
        PriorityQueue<HeapItem> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        int result[] = new int[k * n];

        // 1. Insert first element of each array
        for (int list[] : lists) {
            pq.add(new HeapItem(list[0], list, 1));
        }

        int idx = 0;

        // 2. Add top element to result
        // 3. Get the list amd the next idx of that element
        // 4. Push the next element to min heap
        while (!pq.isEmpty()) {
            HeapItem smallest = pq.poll();
            result[idx++] = smallest.val;

            // Getting next idx and list
            int nextIdx = smallest.nextItemIdx;
            int list[] = smallest.list;

            // Pushing next item to min heap
            if (nextIdx < list.length) {
                pq.add(new HeapItem(list[nextIdx], list, nextIdx + 1));
            }
        }

        for (int val : result) {
            System.out.print(val + " ");
        }

    }
}
