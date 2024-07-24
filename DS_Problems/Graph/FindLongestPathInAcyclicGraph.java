package DS_Problems.Graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

public class FindLongestPathInAcyclicGraph {
    static Map<Integer, List<int[]>> graph = new HashMap<>();

    public static void main(String[] args) {
        int[][] edges = {
                { 3, 2, 1 },
                { 1, 4, 2 },
                { 1, 2, 3 },
                { 2, 4, 5 },
                { 1, 3, 8 },
        };

        for (int i = 0; i < edges.length; i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            List<int[]> newItems = graph.getOrDefault(from, new ArrayList<>());
            newItems.add(new int[] { to, weight });
            graph.put(from, newItems);
        }

        int nodes = 4;
        findLongestPath(nodes, 1);
    }

    public static void findLongestPath(int nodes, int src) {
        boolean[] vis = new boolean[nodes + 1];
        int[] distance = new int[nodes + 1];
        Stack<Integer> s = new Stack<>();

        for (int node = 1; node <= nodes; node++) {
            if (!vis[node]) {
                topoSort(node, vis, s);
            }
        }

        for (int node = 1; node <= nodes; node++) {
            distance[node] = Integer.MIN_VALUE;
        }

        distance[src] = 0;

        while (!s.isEmpty()) {
            int node = s.pop();
            for (int[] neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                int neighborNode = neighbor[0];
                if (distance[neighborNode] < distance[node] + neighbor[1]) {
                    distance[neighborNode] = distance[node] + neighbor[1];
                }
            }
        }

        for (int node = 1; node <= nodes; node++) {
            System.out.println(node + " -> " + distance[node]);
        }
    }

    private static void topoSort(int node, boolean[] vis, Stack<Integer> s) {
        vis[node] = true;

        for (int[] neighbor : graph.getOrDefault(node, new ArrayList<>())) {
            int neighborNode = neighbor[0];
            if (!vis[neighborNode]) {
                topoSort(neighborNode, vis, s);
            }
        }

        s.add(node);
    }
}
