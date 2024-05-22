package Algo_Problems.TwoPointers.Medium;

/*
 * You are given an integer array height of length n. There are n 
 * vertical lines drawn such that the two endpoints of the ith line 
 * are (i, 0) and (i, height[i]). Find two lines that together with 
 * the x-axis form a container, such that the container contains the 
 * most water. Return the maximum amount of water a container can store.
 */

public class ContainerWithMostWater {
    public static void main(String[] args) {
        int heights[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        solve(heights);
    }

    static void solve(int heights[]) {
        int i = 0, j = heights.length - 1;
        int maxWater = Integer.MIN_VALUE;

        while (i < j) {
            int curAmt = (j - i) * Math.min(heights[i], heights[j]);
            maxWater = Math.max(maxWater, curAmt);

            if (heights[i] > heights[j])
                j--;
            else
                i++;
        }

        System.out.println("Max Water: " + maxWater);
    }
}
