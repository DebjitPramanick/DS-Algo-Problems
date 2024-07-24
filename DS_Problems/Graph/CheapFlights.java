package DS_Problems.Graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

/*

There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] 
indicates that there is a flight from city fromi to city toi with 
cost pricei.

You are also given three integers src, dst, and k, return the cheapest 
price from src to dst with at most k stops. If there is no such route, 
return -1.


1. Using Disjkstra
2. Storing number of stops in the queue to check if it exceeds value of k

*/

public class CheapFlights {
    static int[][] flights = { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 }, { 0, 3, 50 }, { 3, 2, 20 } };
    static int N_ACCEPTABLE_STOPS = 2;

    public static void main(String[] args) {
        int src = 0;
        int destination = 2;
        solve(src, destination, N_ACCEPTABLE_STOPS);
    }

    public static void solve(int src, int dest, int nAcceptableStops) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        Map<Integer, List<int[]>> graph = new HashMap<>();
        int finalCost = Integer.MAX_VALUE;

        for (int i = 0; i < flights.length; i++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            List<int[]> newItems = graph.getOrDefault(from, new ArrayList<>());
            newItems.add(new int[] { price, to });
            graph.put(from, newItems);
        }

        pq.add(new int[] { 0, src, 0 });

        while (!pq.isEmpty()) {
            int[] entry = pq.poll();
            int price = entry[0];
            int from = entry[1];
            int nCurrentStops = entry[2];

            if (nCurrentStops > nAcceptableStops) {
                continue;
            }

            if (from == dest && price < finalCost) {
                finalCost = price;
            }

            for (int[] neighbors : graph.getOrDefault(from, new ArrayList<>())) {
                int neighborPrice = neighbors[0];
                int neighborDest = neighbors[1];
                pq.add(new int[] { price + neighborPrice, neighborDest, nCurrentStops + 1 });
            }
        }

        System.out.println("Final cost is: " + finalCost);

    }
}
