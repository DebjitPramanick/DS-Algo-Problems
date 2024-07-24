package DS_Problems.Graph;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class MST {

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
            List<int[]> newItemsForFrom = graph.getOrDefault(from, new ArrayList<>());
            List<int[]> newItemsForTo = graph.getOrDefault(to, new ArrayList<>());
            newItemsForFrom.add(new int[] { to, weight });
            newItemsForTo.add(new int[] { from, weight });
            graph.put(from, newItemsForFrom);
            graph.put(to, newItemsForTo);
        }

        int nodes = 4;

        primsMST(nodes);
        System.out.println("");
        kruskalMST(edges, nodes);
    }

    public static void kruskalMST(int[][] edges, int nodes) {
        int cost = 0;
        int[] parents = new int[nodes + 1];
        int[] ranks = new int[nodes + 1];
        List<int[]> mst = new ArrayList<>();

        // Sort edges by ascending weights
        Arrays.sort(edges, (a, b) -> a[2] - b[2]);

        for (int i = 1; i <= nodes; i++) {
            parents[i] = i;
        }

        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int neighborWeight = edge[2];
            if (findParent(from, parents) != findParent(to, parents)) {
                cost += neighborWeight;
                mst.add(new int[] { from, to });
                makeUnion(from, to, parents, ranks);
            }
        }

        for (int[] entry : mst) {
            System.out.println(entry[0] + " -> " + entry[1]);
        }
        System.out.println("Cost of mst is: " + cost);

    }

    public static void primsMST(int nodes) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int[] weights = new int[nodes + 1];
        int[] parents = new int[nodes + 1];
        boolean[] includedInMST = new boolean[nodes + 1];

        for (int i = 1; i <= nodes; i++) {
            parents[i] = -1;
            weights[i] = Integer.MAX_VALUE;
            includedInMST[i] = false;
        }

        weights[1] = 0;
        pq.add(new int[] { 0, 1 });

        while (!pq.isEmpty()) {
            int[] entry = pq.poll();
            int node = entry[1];

            includedInMST[node] = true;

            for (int[] neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                if (!includedInMST[neighbor[0]] && neighbor[1] < weights[neighbor[0]]) {
                    parents[neighbor[0]] = node;
                    weights[neighbor[0]] = neighbor[1];
                    pq.add(new int[] { neighbor[1], neighbor[0] });
                }
            }
        }

        for (int i = 1; i <= nodes; i++) {
            System.out.println(parents[i] + " -> " + i);
        }
    }

    private static int findParent(int node, int[] parents) {
        if (parents[node] == node) {
            return node;
        }
        int par = parents[node];
        return findParent(par, parents);
    }

    private static void makeUnion(int node1, int node2, int[] parents, int[] ranks) {
        int par1 = findParent(node1, parents);
        int par2 = findParent(node2, parents);

        if (ranks[par1] > ranks[par2]) {
            parents[par2] = par1;
        } else if (ranks[par1] < ranks[par2]) {
            parents[par1] = par2;
        } else {
            parents[par1] = par2;
            ranks[par1]++;
        }
    }
}
