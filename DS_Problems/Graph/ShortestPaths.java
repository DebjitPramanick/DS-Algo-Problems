package DS_Problems.Graph;

import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

public class ShortestPaths {

    static Map<Integer, List<Integer>> adjList;
    static Map<Integer, List<int[]>> weightedAdjList;

    public static void main(String[] args) {
        Graph graph = new Graph(5, 6, false);
        graph.display();
        adjList = graph.getGraph();
        shortestPaths(2, 5);
        djkstra(2, 5);
    }

    public static void shortestPaths(int src, int nodes) {
        Queue<Integer> q = new LinkedList<>();
        int[] distances = new int[nodes + 1];

        for (int i = 1; i <= nodes; i++) {
            distances[i] = Integer.MAX_VALUE;
        }

        q.add(src);
        distances[src] = 0;

        while (!q.isEmpty()) {
            int node = q.poll();
            int dist = distances[node];
            for (Integer neighbor : adjList.get(node)) {
                if (dist + 1 < distances[neighbor]) {
                    distances[neighbor] = dist + 1;
                    q.add(neighbor);
                }
            }
        }

        for (int i = 1; i <= nodes; i++) {
            System.out.println("Shortest distance from " + src + " to " + i + " is " + distances[i]);
        }
    }

    public static void djkstra(int src, int nodes) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int[] dist = new int[nodes + 1];

        for (int i = 1; i <= nodes; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        pq.add(new int[] { 0, src });
        dist[src] = 0;

        while (!pq.isEmpty()) {
            int[] entry = pq.poll();
            int node = entry[1];

            for (int[] neighbor : weightedAdjList.get(node)) {
                int neighborNode = neighbor[1];
                int neighborWeight = neighbor[0];
                if (neighborWeight + dist[node] <= dist[neighborNode]) {
                    dist[neighborNode] = neighborWeight + dist[node];
                    pq.add(new int[] { dist[neighborNode], neighborNode });
                }
            }
        }

        for (int i = 1; i <= nodes; i++) {
            System.out.println("Shortest distance from " + src + " to " + i + " is " + dist[i]);
        }
    }

}
